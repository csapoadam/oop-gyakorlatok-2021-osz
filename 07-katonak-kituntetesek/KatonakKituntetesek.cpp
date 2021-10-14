// KatonakKituntetesek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "kituntetesek.h"

int main()
{
	Kituntetes kit1("Arany Akarmi Kereszt", 1997); // rvalue
	Kituntetes kit2("Mas nincs is, mint kereszt", 2002);
	kit1.print();
	kit2.print();
}
