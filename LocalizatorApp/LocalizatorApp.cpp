#include <iostream>
#include "DllFunctions.h"

using namespace std;

int main()
{
	while (true)
	{
		cout << "Path to XML file:";
		std::string pathFile;
		std::getline(std::cin, pathFile);
		if (!ReadXML(pathFile))
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
		cout << "Value: " + GetWorld(keyValue);

	}
}