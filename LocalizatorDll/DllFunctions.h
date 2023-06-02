#pragma once
#include <string>


extern "C" __declspec(dllexport) void Start();

extern "C" __declspec(dllexport) void Stop();

extern "C" __declspec(dllexport) void SetSelectLanguage(const char*);

extern "C" __declspec(dllexport) const char* GetSelectLanguage();

extern "C" __declspec(dllexport) const char* GetWord(const char*);

extern "C" __declspec(dllexport) const char* GetLanguageNamesStr();

extern "C" __declspec(dllexport) const char** GetLanguageNames(int& size);