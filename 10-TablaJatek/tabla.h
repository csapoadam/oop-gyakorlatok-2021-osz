#pragma once
#include <vector>
#include <iostream>
#include <map>

#include "babuk.h"

typedef std::pair<int, int> cellCoords;

class Tabla {
	std::vector< std::vector<Babu*> > tabla; // a vektor minden eleme egy sor
	int szSorok;
	int szOszlopok;

	std::vector <cellCoords> getSzomszedok(int sor, int oszlop) {
		std::vector< cellCoords > retval;
		for (int i = -1; i < 2; i++) {
			int newsor = sor + i;
			if (newsor < szSorok && newsor > -1) {
				// meg benne vagyunk a tablaban!
				retval.push_back(std::make_pair(newsor, oszlop));
			}
		}
		for (int i = -1; i < 2; i++) {
			int newoszlop = oszlop + i;
			if (newoszlop < szOszlopok && newoszlop > -1
				&& newoszlop != oszlop) {
				// ne adjuk ketszer hozza a sor, oszlop koordinatat!
				// meg benne vagyunk a tablaban!
				retval.push_back(std::make_pair(sor, newoszlop));
			}
		}
		return retval;
	}
public:
	Tabla(int sorok, int oszlopok) : szSorok(sorok), szOszlopok(oszlopok) {
		for (int s = 0; s < szSorok; s++) {
			// letre kell hoznunk egy szOszlopok hosszu vektort nullptr-ekkel
			tabla.push_back(std::vector<Babu*>(szOszlopok, nullptr));
		}
	}
	~Tabla() {
		for (auto& sor : tabla) {
			for (auto& cella : sor) {
				if (cella != nullptr) {
					delete cella;
				}
			}
		}
	}
	// tiltsuk le a copy constructort es assignmentet!
	Tabla(const Tabla&) = delete;
	Tabla& operator=(const Tabla&) = delete;

	void createBabu(int coordX, int coordY, BabuTypes bt) {
		try { // .at() miatt!
			if (bt == BabuTypes::Aligator) {
				std::cout << "creating aligator at cell ";
				tabla.at(coordX).at(coordY) = new Aligator();
			}
			else if (bt == BabuTypes::Csirke) {
				std::cout << "creating csirke at cell ";
				tabla.at(coordX).at(coordY) = new Csirke();
			}
			else if (bt == BabuTypes::Ember) {
				std::cout << "creating ember at cell ";
				tabla.at(coordX).at(coordY) = new Ember();
			}
			std::cout << coordX << ", " << coordY << std::endl;
		}
		catch (std::out_of_range const& exc) {
			std::cout << std::endl << exc.what() << std::endl;
		}
	}

	void leptet() {
		for (int sorSz = 0; sorSz < szSorok; sorSz++) {
			for (int oszlopSz = 0; oszlopSz < szOszlopok; oszlopSz++) {
				Babu* cella = tabla[sorSz][oszlopSz];
				if (cella) { // ha nullptr, nincs mit csinalni! (else ag)
					std::vector<cellCoords> szomszedok =
						getSzomszedok(sorSz, oszlopSz);
					std::cout << "Tabla " << sorSz << ". soranak es ";
					std::cout << oszlopSz << ". oszlopanak szomszedai:";
					std::cout << std::endl;
					for (auto sz : szomszedok) {
						std::cout << "\t" << sz.first << ", " << sz.second;
						std::cout << std::endl;
					}
				}
			}
		}
	}

	void print() {
		for (int s = 0; s < szSorok; s++) {
			std::cout << "|";
			for (auto cella : tabla[s]) {
				if (!cella) { // ha nullptr
					std::cout << " 0 |";
				}
				else {
					std::cout << " " << cella->char_rep() << " |";
				}
			}
			std::cout << std::endl;
		}
	}
};