#pragma once
#include <vector>
#include <string>

class MenuItem {
	std::string text;
	double price;
public:
	MenuItem(const std::string& s, double d) :
		text(s), price(d)
	{}
	void print();
};


class Menu {
	std::vector<MenuItem*> items;
public:
	void addItem(MenuItem* mip);
	void print();
};



