#pragma once
#include <string>


//class DllFunctions
//{
//};


extern "C" __declspec(dllexport) bool ReadXML(std::string);

extern "C" __declspec(dllexport) std::string GetWorld(std::string);