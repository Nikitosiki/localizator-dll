#pragma once
#include <string>
#include <unordered_map>
#include "language.h"

class LocalizerHandler
{
private:
	std::unordered_map<std::string, std::string>* dictionary;
	std::vector<language>* languages;

	const std::string GetDllFolderPath() const;

	const bool CheckCorrectDictionary(const std::vector<std::string>& keys, const std::unordered_map<std::string, std::string>& dictionary) const;

	const bool CheckAllTranslationsExist(const std::string& folderPath, const std::vector<language>& languages) const;

	const void MessageError(const HWND& hWnd, const LPCSTR& lpText, const LPCSTR& lpCaption, const UINT& uType) const;

	const bool isDuplicates(const std::vector<std::string>& values, std::string& duplicateElement) const;


public:
	LocalizerHandler();
	~LocalizerHandler();

	// Метод для возврата значения по ключу из unordered_map
	const std::string& GetValue(const std::string& key) const;

	const void SetLanguage(const std::string& nameLanguage) const;

	const std::string GetSelectLanguageName() const;

	const std::string GetLanguageNames() const;

	const char** GetLanguageNames(int& size) const;
};

