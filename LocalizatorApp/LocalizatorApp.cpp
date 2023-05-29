#include <iostream>
#include "DllFunctions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "en_US.utf8");
	 
	try
	{

		Start();
		cout << GetLanguageNames();
		/*std::string keyValue;
		while (true)
		{
			cout << "\n\nWrite the key:";
			cin >> keyValue;
			cout << "Value: " << GetWord(keyValue.c_str());

		}*/
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