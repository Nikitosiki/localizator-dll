# LocalizatorApp

Compiled .dll in the \bin folder of the LocalizatorApp project.
Unzip language.rar and place next to .dll !!!

Description Functions:
  extern "C" __declspec(dllexport) void Start();
  extern "C" __declspec(dllexport) void Stop();
  extern "C" __declspec(dllexport) void SetSelectLanguage(const char*);
  extern "C" __declspec(dllexport) const char* GetSelectLanguage();
  extern "C" __declspec(dllexport) const char* GetWord(const char*);
  extern "C" __declspec(dllexport) const char* GetLanguageNamesStr();
  extern "C" __declspec(dllexport) const char** GetLanguageNames(int& size);
