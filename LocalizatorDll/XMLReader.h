#pragma once
#include <string>
#include <unordered_map>

class XMLReader
{
private:
    std::unordered_map<std::string, std::string> translations;

public:
    // Метод для считывания файла XML и сохранения его в unordered_map
    bool LoadFile(const std::string&);

    // Метод для возврата значения по ключу из unordered_map
    const std::string& GetValue(const std::string&) const;
};