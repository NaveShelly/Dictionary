#ifndef MENU_H
#define Menu_H
#include "Dictionary.h"
class Menu {
private:
	Dictionary* Info;
	friend class Dicitionary;
public:
	friend class Dictionary;
	Menu();
	~Menu();
	Menu(const Menu& x);
	void MainMenu();
};
#endif // !MENU
