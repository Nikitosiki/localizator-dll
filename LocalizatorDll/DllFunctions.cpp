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

extern "C" __declspec(dllexport) void SetSelectLanguage(const char* nameLang)
{
	if (!localizator)
		Start();

	localizator->SetLanguage(nameLang);
}

extern "C" __declspec(dllexport) const char** GetLanguageNames(int& size)
{
	if (!localizator)
		Start();

	return localizator->GetLanguageNames(size);
}

char* tempOutput_GetLanguageName = nullptr;
extern "C" __declspec(dllexport) const char* GetSelectLanguage()
{
	if (!localizator)
		Start();

	if (tempOutput_GetLanguageName)
	{
		delete tempOutput_GetLanguageName;
		tempOutput_GetLanguageName = nullptr;
	}

	const std::string& temp = localizator->GetSelectLanguageName();
	tempOutput_GetLanguageName = new char[temp.length()];
	std::copy(temp.c_str(), temp.c_str() + temp.length(), tempOutput_GetLanguageName);
	tempOutput_GetLanguageName[temp.length()] = '\0';
	return tempOutput_GetLanguageName;
}

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
	std::copy(temp.c_str(), temp.c_str() + temp.length(), tempOutput_GetLanguageNames);
	tempOutput_GetLanguageNames[temp.length()] = '\0';
	return tempOutput_GetLanguageNames;
}

extern "C" __declspec(dllexport) void Stop()
{
	if (localizator) delete localizator;
	if (tempOutput_GetLanguageName) delete tempOutput_GetLanguageName;
	if (tempOutput_GetLanguageNames) delete tempOutput_GetLanguageNames;
}