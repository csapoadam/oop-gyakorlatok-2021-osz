#include "menu.h"
#include <iostream>

void Menu::addItem(MenuItem* mip) {
	items.push_back(mip);
}

void Menu::print() {
	std::cout << "Etlap:" << std::endl;
	int itemnum = 1;
	for (MenuItem* mip : items) {
		std::cout << itemnum++ << ": ";
		mip->print();
		std::cout << std::endl;
	}
}

void MenuItem::print() {
	std::cout << text << " - (";
	std::cout << price << " USD)";
}
