#include "pch.h"
#include "DllFunctions.h"
#include "XMLReader.h"

XMLReader dictionary;

extern "C" __declspec(dllexport) bool ReadXML(const char* pathFile)
{
	try
	{
		return dictionary.LoadFile(pathFile);
	}
	catch (const std::exception&)
	{
		return false;
	}
}

extern "C" __declspec(dllexport) const char* GetWord(const char* key)
{
	return dictionary.GetValue(key).c_str();
}