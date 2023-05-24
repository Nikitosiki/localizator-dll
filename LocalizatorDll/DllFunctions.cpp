#include "pch.h"
#include "DllFunctions.h"
#include "XMLReader.h"

XMLReader dictionary;

extern "C" __declspec(dllexport) bool ReadXML(std::string pathFile)
{
	try
	{
		dictionary.LoadFile(pathFile);
	}
	catch (const std::exception&)
	{
		return false;
	}

	return true;
}

extern "C" __declspec(dllexport) std::string GetWorld(std::string key)
{
	return dictionary.GetValue(key);
}