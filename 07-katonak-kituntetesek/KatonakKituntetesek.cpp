// KatonakKituntetesek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "kituntetesek.h"
#include "katonak.h"

int main()
{
	Katona x("Eros Pista", "Hadnagy", 1977);
	Katona y("Harcos Helga", "Ezredes", 1979);

	// az addPlecsni() metodus hozza letre a kituntetes objektumokat!
	x.addPlecsni("Arany Akarmi Kereszt", 1997);
	x.addPlecsni("Arany Felso Kereszt", 2002);
	y.addPlecsni("Arany Facan a Legjobb!", 2005);

	x.print();
	y.print();
}
