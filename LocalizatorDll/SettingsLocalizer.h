#pragma once
#include <string>

class SettingsLocalizer
{

private:
	static std::string language;

public:
	static std::string getLanguage();

	static bool setLanguage(const std::string& datalang);

};

