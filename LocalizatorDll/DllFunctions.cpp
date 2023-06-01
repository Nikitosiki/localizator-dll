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

extern "C" __declspec(dllexport) const char** GetLanguageNamesArr(int& size)
{
	if (!localizator)
		Start();

	return localizator->GetLanguageNames(size);
}

// Bad Code
char* tempOutput_GetLanguageNames = nullptr;
extern "C" __declspec(dllexport) const char* GetLanguageNamesStr()
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