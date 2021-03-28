#include "Menu.h"
Menu::Menu()
{
	Info = new Dictionary[1];
}
Menu::~Menu()
{
	delete Info;
}
Menu::Menu(const Menu& x)
{
	Info[0].operator=(x.Info[0]);
}
void Menu::MainMenu()
{
	int Case = 0;
	while (Case >= 0 && Case <= 6)
	{
		cout << "Hello This is your options for the dictionary" << endl;
		cout << "To Create Dictionary Press 1" << endl;
		cout << "To Enter A new Defintion Press 2" << endl;
		cout << "To Insert A new Translation press 3" << endl;
		cout << "To Fine A Defintion in the dictionary press 4" << endl;
		cout << "To see the same Defintion in anoter Word press 5" << endl;
		cout << "To exit press 6" << endl;
		cin >> Case;
		switch (Case)
		{
		case 1:
		{
			cout << "Getting Ready To Create Dictionary" << endl;
			(*Info).operator >> ((*Info));
			cout << "Your Dictionary is Ready" << endl;
			break;
		}
		case 2:
		{
			cout << "Getting Ready To Create Another Definition" << endl;
			(*Info).AddDefinition((*Info));
			break;
		}
		case 3:
		{
			cout << "Getting Ready To Create New Definition For Your Word" << endl;
			(*Info)=(*Info).NewDefinition((*Info));
			break;
		}
		case 4:
		{
			char tmp[80];
			int answer = 0;
			cout << "Enter a Word To See her Definitions " << endl;
			while (answer != 1)
			{
				cout << "Enter Illegeal Word" << endl;
				cin >> tmp;
				answer = FixWord(tmp);
			}
			(*Info).FindDefWord(tmp);
			break;
		}
		case 5:
		{
			(*Info).EqaulDefines();
		}		
		case 6:
		{
			this->~Menu();
			exit(1);
		}
		}
	}
}