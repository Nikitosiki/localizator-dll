#pragma once
#include <string>


//class DllFunctions
//{
//};


extern "C" __declspec(dllexport) bool ReadXML(const char*);

extern "C" __declspec(dllexport) const char* GetWord(const char*);