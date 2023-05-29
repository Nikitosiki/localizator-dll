#pragma once
#include <string>


extern "C" __declspec(dllexport) void Start();

extern "C" __declspec(dllexport) const char* GetWord(const char*);

extern "C" __declspec(dllexport) const char* GetLanguageNames();