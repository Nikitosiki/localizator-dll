#include <iostream>
#include "DllFunctions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "en_US.utf8");
	 
	try
	{

		Start();
		//cout << GetLanguageNamesStr();

		int size;
		const char** mas = GetLanguageNames(size);
		for (int i = 0; i < size; i++)
		{
			cout << mas[i] << endl;
		}
		cout << "-------------------------------------" << endl;
		cout << "Select: " << GetSelectLanguage() << endl;
		cout << "-------------------------------------" << endl << endl;

		std::string keyValue;
		cout << "Change the language? (y/n)" << endl;
		cin >> keyValue;
		if (keyValue == "y" || keyValue == "yes")
		{
			cout << "Language name: ";
			cin >> keyValue;
			SetSelectLanguage(keyValue.c_str());
			cout << "Clouse App!" << endl;
			Stop();
			return 0;
		}

		//while (true)
		{
			cout << "\n\nWrite the key:";
			cin >> keyValue;
			cout << "Value: " << GetWord(keyValue.c_str());

		}

		Stop();

	}
	catch (const char* exp)
	{
		cout << exp;
	}

	/*while (true)
	{
		cout << "Path to XML file:";
		std::string pathFile;
		std::getline(std::cin, pathFile);
		if (!ReadXML(pathFile.c_str()))
		{
			cout << "Error load file!";
			continue;
		}
		else
			break;
	}

	std::string keyValue;
	while (true)
	{
		cout << "\n\nWrite the key:";
		cin >> keyValue;
		cout << "Value: " << GetWord(keyValue.c_str());

	}*/
}