#include "pch.h"
#include "SettingsLocalizer.h"

std::string SettingsLocalizer::language;

std::string SettingsLocalizer::getLanguage()
{
	return language;
}

bool SettingsLocalizer::setLanguage(const std::string& datalang)
{
	if (!datalang.empty())
	{
		language = datalang;
		return true;
	}
	else
		return false;
}