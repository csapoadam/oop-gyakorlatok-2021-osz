#pragma once
#include <vector>
#include <iostream>

#include "babuk.h"

class Tabla {
	std::vector< std::vector<Babu*> > tabla; // a vektor minden eleme egy sor
	int szSorok;
	int szOszlopok;
public:
	Tabla(int sorok, int oszlopok) : szSorok(sorok), szOszlopok(oszlopok) {
		for (int s = 0; s < szSorok; s++) {
			// letre kell hoznunk egy szOszlopok hosszu vektort nullptr-ekkel
			tabla.push_back(std::vector<Babu*>(szOszlopok, nullptr));
		}
	}
	void createBabu(int coordX, int coordY, BabuTypes bt) {
		if (bt == BabuTypes::Aligator) {
			std::cout << "creating aligator at cell ";
		}
		else if (bt == BabuTypes::Csirke) {
			std::cout << "creating csirke at cell ";
		}
		else if (bt == BabuTypes::Ember) {
			std::cout << "creating ember at cell ";
		}
		std::cout << coordX << ", " << coordY << std::endl;
	}
	void print() {
		for (int s = 0; s < szSorok; s++) {
			std::cout << "|";
			for (auto cella : tabla[s]) {
				if (!cella) { // ha nullptr
					std::cout << " 0 |";
				}
			}
			std::cout << std::endl;
		}
	}
};