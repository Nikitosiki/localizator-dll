#include "pch.h"
#include "LocalizatorHandler.h"

extern "C" __declspec(dllexport) bool Start()
{
	SettingsLocalizer::setLanguage("default");
	return true;
}

extern "C" __declspec(dllexport) bool ChangeLanguage(std::string selectLanguage)
{
	SettingsLocalizer::setLanguage(selectLanguage);
	return true;
}

extern "C" __declspec(dllexport) std::string ÑurrentLanguage()
{
	return SettingsLocalizer::getLanguage();
}
