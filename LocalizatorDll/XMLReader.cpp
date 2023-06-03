#include <iostream>
#include <string>
#include <unordered_map>
#include "pch.h"
#include "XMLReader.h"
#include "pugixml.hpp"
#include "language.h"

using namespace pugi;


const bool XMLReader::ReadLanguagesFromFile(const std::string& fileFullPath, std::vector<language>& languages)
{
    xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    xml_node availableLanguagesNode = doc.select_node("/settings/available_languages").node();
    if (availableLanguagesNode.empty()) {
        return false;
    }

    // Очищаем текущий unordered_map перед загрузкой новых данных
    languages.clear();


    for (xml_node languageNode : availableLanguagesNode.children("language")) {
        language newlanguage;
        newlanguage.code = languageNode.attribute("code").as_string();
        newlanguage.name = languageNode.attribute("name").as_string();
        newlanguage.file = languageNode.attribute("file").as_string();
        languages.push_back(newlanguage);
    }

    return true;
}

const bool XMLReader::ReadKeysFromFile(const std::string& fileFullPath, std::vector<std::string>& values)
{
    pugi::xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    pugi::xml_node keysNode = doc.child("keys");
    if (!keysNode)
    {
        return false;
    }

    for (pugi::xml_node keyNode = keysNode.child("key"); keyNode; keyNode = keyNode.next_sibling("key"))
    {
        values.push_back(keyNode.attribute("value").as_string());
    }
}

const bool XMLReader::ReadSelectLangFile_FromFile(const std::string& fileFullPath, std::string& values)
{
    pugi::xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    pugi::xml_node selectedLanguageNode = doc.select_node("/settings/selected_language").node();
    if (!selectedLanguageNode)
    {
        return false;
    }

    pugi::xml_node availableLanguagesNode = doc.child("settings").child("available_languages");
    if (!availableLanguagesNode)
    {
        return false;
    }

    std::string selectedLanguageCode = selectedLanguageNode.attribute("code").as_string();

    for (pugi::xml_node languageNode = availableLanguagesNode.child("language"); languageNode; languageNode = languageNode.next_sibling("language"))
    {
        std::string languageCode = languageNode.attribute("code").as_string();
        if (languageCode == selectedLanguageCode)
        {
            values = languageNode.attribute("file").as_string();
            return true;
        }
    }

    return false;
}

const bool XMLReader::ReadSelectLangName_FromFile(const std::string& fileFullPath, std::string& values)
{
    pugi::xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    pugi::xml_node selectedLanguageNode = doc.select_node("/settings/selected_language").node();
    if (!selectedLanguageNode)
    {
        return false;
    }

    pugi::xml_node availableLanguagesNode = doc.child("settings").child("available_languages");
    if (!availableLanguagesNode)
    {
        return false;
    }

    std::string selectedLanguageCode = selectedLanguageNode.attribute("code").as_string();

    for (pugi::xml_node languageNode = availableLanguagesNode.child("language"); languageNode; languageNode = languageNode.next_sibling("language"))
    {
        std::string languageCode = languageNode.attribute("code").as_string();
        if (languageCode == selectedLanguageCode)
        {
            values = languageNode.attribute("name").as_string();
            return true;
        }
    }

    return false;
}

const bool XMLReader::ReadFromFileConstructor(const std::string& fileFullPath, const std::string& selectNode, const std::string& selectChildren, const std::string& selectAttribute, std::string& value)
{
    xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    xml_node node = doc.select_node(selectNode.c_str()).node();
    if (node.empty()) {
        return false;
    }

    xml_node entry = node.child(selectChildren.c_str());
    if (entry.empty()) {
        return false;
    }

    value = entry.attribute(selectAttribute.c_str()).as_string();
    if (value.empty()) {
        return false;
    }

    return true;
}

const bool XMLReader::ReadTranslationsFromFile(const std::string& fileFullPath, std::unordered_map<std::string, std::string>& dictionary)
{
    pugi::xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    pugi::xml_node translationsNode = doc.child("translations");
    if (!translationsNode)
    {
        return false;
    }

    for (pugi::xml_node entryNode = translationsNode.child("entry"); entryNode; entryNode = entryNode.next_sibling("entry"))
    {
        std::string key = entryNode.attribute("key").as_string();
        std::string value = entryNode.attribute("value").as_string();
        dictionary[key] = value;
    }

    return true;
}

const bool XMLReader::ModifySelectLangFile(const std::string& fileFullPath, const std::string& nameLang)
{
    pugi::xml_document doc;
    if (!doc.load_file(fileFullPath.c_str()))
    {
        return false;
    }

    // Находим элемент <selected_language>
    pugi::xml_node selectedLanguageNode = doc.select_node("//selected_language").node();
    if (!selectedLanguageNode)
    {
        return false;
    }

    // Находим соответствующий язык по имени в разделе <available_languages>
    pugi::xml_node availableLanguagesNode = doc.select_node("//available_languages").node();
    if (!availableLanguagesNode)
    {
        return false;
    }

    std::string newCode;

    for (pugi::xml_node languageNode : availableLanguagesNode.children("language"))
    {
        std::string name = languageNode.attribute("name").as_string();

        if (name == nameLang)
        {
            newCode = languageNode.attribute("code").as_string();
            break;
        }
    }

    if (newCode.empty())
    {
        return false;
    }

    // Изменяем значение атрибута code в элементе <selected_language>
    selectedLanguageNode.attribute("code").set_value(newCode.c_str());

    if (!doc.save_file(fileFullPath.c_str()))
    {
        return false;
    }

    return true;
}

