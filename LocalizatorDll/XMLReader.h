#pragma once
#include <string>
#include <unordered_map>
#include "language.h"

class XMLReader
{
public:
	static const bool ReadLanguagesFromFile(const std::string& fileFullPath, std::vector<language>& languages);
};