#include "pch.h"
#include "XMLReader.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "pugixml.hpp"

using namespace pugi;


// Метод для считывания файла XML и сохранения его в unordered_map
bool XMLReader::LoadFile(const std::string& filePath)
{
    xml_document doc;
    if (!doc.load_file(filePath.c_str()))
    {
        return false;
    }

    // Очищаем текущий unordered_map перед загрузкой новых данных
    translations.clear();

    xml_node root = doc.child("translations");
    if (!root)
    {
        return false;
    }

    for (xml_node entry = root.child("entry"); entry; entry = entry.next_sibling("entry"))
    {
        std::string key = entry.attribute("key").as_string();
        std::string value = entry.attribute("value").as_string();
        translations[key] = value;
    }

    return true;
}

// Метод для возврата значения по ключу из unordered_map
const std::string& XMLReader::GetValue(const std::string& key) const
{
    auto iter = translations.find(key);
    if (iter != translations.end())
    {
        return iter->second;
    }
    else
    {
        return 0;
    }
}


