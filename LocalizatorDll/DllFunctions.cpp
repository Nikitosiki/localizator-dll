#include "pch.h"
#include "DllFunctions.h"
#include "LocalizerHandler.h"


LocalizerHandler* localizator;

extern "C" __declspec(dllexport) void Start()
{
	localizator = new LocalizerHandler();
}

extern "C" __declspec(dllexport) const char* GetWord(const char* key)
{
	if (!localizator)
		Start();

	return localizator->GetValue(key).c_str();
}

char* tempOutput_GetLanguageNames = nullptr;
extern "C" __declspec(dllexport) const char* GetLanguageNames()
{
	if (!localizator)
		Start();

	if (tempOutput_GetLanguageNames)
	{
		delete tempOutput_GetLanguageNames;
		tempOutput_GetLanguageNames = nullptr;
	}

	const std::string& temp = localizator->GetLanguageNames();
	tempOutput_GetLanguageNames = new char[temp.length()];
	std::copy(temp.c_str(), temp.c_str() + temp.length() - 1, tempOutput_GetLanguageNames);
	return tempOutput_GetLanguageNames;
}