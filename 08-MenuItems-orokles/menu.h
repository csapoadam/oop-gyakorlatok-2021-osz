#pragma once
#include <vector>
#include <string>
#include <iostream>

class MenuItem {
	std::string text;
	double price;
public:
	MenuItem(const std::string& s, double d) :
		text(s), price(d)
	{}
	void print();
	double getPrice() { return price; }
};


class Menu {
	std::vector<MenuItem*> items;
public:
	void addItem(MenuItem* mip);
	void print();
	MenuItem* getNthItem(int n) {
		if (n > items.size()) {
			return nullptr;
		}
		else {
			return items[n - 1];
		}
	}
};

class DiscountedItem : public MenuItem {
	const double discountFactor;
	double originalPrice;
public:
	DiscountedItem(const std::string& s,
		double originalP,
		double dfactor) :
			MenuItem(s, dfactor * originalP),
			discountFactor(dfactor),
			originalPrice(originalP)
		// szebben meg lehetne oldani virtualis
		// print metodussal, de errol majd kesobb
	{
	}
};

class Buy1Get1Free : public MenuItem {
public:
	Buy1Get1Free(const std::string& s,
		double p) : MenuItem(s, p) {}
};

class Rendeles {
	double subtotal;
public:
	Rendeles() : subtotal(0) {}
	void rendel(Menu*, int);
	void fizet();
};



