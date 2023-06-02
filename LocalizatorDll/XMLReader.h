#pragma once
#include <string>
#include <unordered_map>
#include "language.h"

class XMLReader
{
public:
	static const bool ReadLanguagesFromFile(const std::string& fileFullPath, std::vector<language>& languages);

	static const bool ReadKeysFromFile(const std::string& fileFullPath, std::vector<std::string>& values);

	static const bool ReadSelectLangFile_FromFile(const std::string& fileFullPath, std::string& values);

	static const bool ReadSelectLangName_FromFile(const std::string& fileFullPath, std::string& values);
	
	static const bool ReadFromFileConstructor(const std::string& fileFullPath, const std::string& selectNode, const std::string& selectChildren, const std::string& selectAttribute, std::string& value);
	
	static const bool ReadTranslationsFromFile(const std::string& fileFullPath, std::unordered_map<std::string, std::string>& dictionary);

	static const bool ModifySelectLangFile(const std::string& fileFullPath, const std::string& nameLang);
};