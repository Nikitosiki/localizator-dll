#pragma once
#include <string>
#include <unordered_map>
#include "language.h"

class XMLReader
{
public:
	static const bool ReadLanguagesFromFile(const std::string& fileFullPath, std::vector<language>& languages);

	static const bool ReadFromFile(const std::string& fileFullPath, const std::string& selectNode, const std::string& selectChildren, const std::string& selectAttribute, std::string& value);
};