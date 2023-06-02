#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "LocalizerHandler.h"
#include "XMLReader.h"


LocalizerHandler::LocalizerHandler()
{
    // Инициализация динамических объектов
    dictionary = new std::unordered_map<std::string, std::string>();
    languages = new std::vector<language>();

    // Получаем путь текущей директории
    const std::string directoryPath = GetDllFolderPath();

    // Загружаем перечень языков из файла настроек
    if (!XMLReader::ReadLanguagesFromFile(directoryPath + "\\language\\settings.xml", *this->languages))
        throw "Error. Reading settings file!";

    // Проверяем что файлы языков существуют
    if (!CheckAllTranslationsExist(directoryPath + "\\language\\dictionaries\\", *this->languages))
        throw "Error. Not all dictionary files exist!";

    // Считываем название файла выбранного языка, в файле настроек
    std::string fileLanguageName;
    if (!XMLReader::ReadSelectLangFile_FromFile(directoryPath + "\\language\\settings.xml", fileLanguageName))
        throw "Error. Reading settings file!";

    // Считываем словарь с нужным переводом
    if (!XMLReader::ReadTranslationsFromFile(directoryPath + "\\language\\dictionaries\\" + fileLanguageName, *this->dictionary))
        throw ("Error. Reading dictionary file: " + fileLanguageName).c_str();

    // Считываем файл со всеми ключами
    std::vector<std::string> keys;
    if (!XMLReader::ReadKeysFromFile(directoryPath + "\\language\\keys.xml", keys))
        throw "Error. Reading keys file!";

    // Проверяем словарь на корректность, используя файл со всеми ключами
    if (!CheckCorrectDictionary(keys, *this->dictionary))
        throw ("Error. Incorrect keys in dictionary, file: " + fileLanguageName).c_str();
}

LocalizerHandler::~LocalizerHandler()
{
    delete dictionary;
    delete languages;
}


// Метод для возврата значения по ключу из unordered_map
const std::string& LocalizerHandler::GetValue(const std::string& key) const
{
    if (dictionary->empty())
        throw "Error. Dictionary file is empty!";

    auto iter = dictionary->find(key);
    if (iter != dictionary->end())
    {
        return iter->second;
    }
    else
    {
        throw "Error. No key in dictionary!";
    }
}

const void LocalizerHandler::SetLanguage(const std::string& nameLanguage) const
{
    if (languages->empty())
        throw "Error. Languages file is empty!";

    if (!XMLReader::ModifySelectLangFile(GetDllFolderPath() + "\\language\\settings.xml", nameLanguage))
        throw "Error. Modify select language!";
}

const std::string LocalizerHandler::GetSelectLanguageName() const
{
    if (languages->empty())
        throw "Error. Languages file is empty!";

    std::string nameSelectLang;
    if (!XMLReader::ReadSelectLangName_FromFile(GetDllFolderPath() + "\\language\\settings.xml", nameSelectLang))
        throw "Error. Reading settings file!";

    return nameSelectLang;
}

const std::string LocalizerHandler::GetLanguageNames() const
{
    if (languages->empty())
        throw "Error. Languages file is empty!";

    std::string names;
    for (const language& languageThis : *languages) {
        if (!names.empty()) {
            names += " ";
        }
        names += languageThis.name;
    }
    return names;
}

const char** LocalizerHandler::GetLanguageNames(int& size) const
{
    if (languages->empty())
        throw "Error. Languages file is empty!";

    size = languages->size();
    const char** languageNames = new const char* [size];

    for (int i = 0; i < size; ++i) {
        languageNames[i] = (*languages)[i].name.c_str();
    }

    return languageNames;
}


// ----------------------------------
// ---------- Helper class ----------
// ----------------------------------

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

const bool LocalizerHandler::CheckCorrectDictionary(const std::vector<std::string>& keys, const std::unordered_map<std::string, std::string>& dictionary) const
{
    if (keys.size() != dictionary.size())
    {
        return false;
    }

    for (const auto& key : keys)
    {
        if (dictionary.find(key) == dictionary.end())
        {
            return false;
        }
    }

    return true;
}

const bool LocalizerHandler::CheckAllTranslationsExist(const std::string& folderPath, const std::vector<language>& languages) const
{
    for (const auto& language : languages)
    {
        std::ifstream file(folderPath + language.file);
        if (!file)
        {
            return false;
        }
    }

    return true;
}