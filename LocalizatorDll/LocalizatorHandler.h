#pragma once
#include <string>
#include "SettingsLocalizer.h"


//class LocalizatorHandler
//{
//
//public:
//
//};



extern "C" __declspec(dllexport) bool Start();

extern "C" __declspec(dllexport) bool ChangeLanguage(std::string);

extern "C" __declspec(dllexport) std::string ÑurrentLanguage();