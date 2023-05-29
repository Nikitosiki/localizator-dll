#include <windows.h>
#include <iostream>
#include <string>
#include "LocalizerHandler.h"
#include "XMLReader.h"


LocalizerHandler::LocalizerHandler()
{
    const std::string directoryPath = GetDllFolderPath();

    if (!XMLReader::ReadLanguagesFromFile(directoryPath + "\\language\\settings.xml", this->languages))
        throw "Error. Reading settings file!";

    //XMLReader::LoadFile(pathFile);
    //throw "Error. File not found!";
}


// Метод для возврата значения по ключу из unordered_map
const std::string& LocalizerHandler::GetValue(const std::string& key) const
{
    if (dictionary.empty())
        throw "Error. Dictionary file is empty!";

    auto iter = dictionary.find(key);
    if (iter != dictionary.end())
    {
        return iter->second;
    }
    else
    {
        throw "Error. No key in dictionary!";
    }
}

const std::string LocalizerHandler::GetLanguageNames() const
{
    if (languages.empty())
        throw "Error. Dictionary file is empty!";

    std::string names;
    for (const language& languageThis : languages) {
        if (!names.empty()) {
            names += " ";
        }
        names += languageThis.name;
    }
    return names;
}

const std::string LocalizerHandler::GetDllFolderPath() const
{
    char path[MAX_PATH];
    HMODULE hModule = GetModuleHandle(NULL);

    if (hModule != NULL)
    {
        GetModuleFileNameA(hModule, path, sizeof(path));

        std::string fullPath(path);
        size_t found = fullPath.find_last_of("\\");
        return fullPath.substr(0, found);
    }

    return "Error. Failed to get project directory. \nModuleHandleException: Failed to retrieve the module handle.";
}