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
	cellCoords getRandomSzomszed(int sorSz, int oszlopSz) {
		std::vector<cellCoords> szomszedok = getSzomszedok(sorSz, oszlopSz);

		if (szomszedok.size() > 0) {
			double rand01 = (double)rand() / RAND_MAX; // 0 es 1 kozotti szam
			double leptek = 1.0 / szomszedok.size();
			int leptekCnt = 1;
			while (true) {
				if (rand01 < (leptekCnt * leptek) + 0.001) {
					return szomszedok[leptekCnt - 1];
				}
				leptekCnt++;
			}
		}
		else {
			return std::make_pair(sorSz, oszlopSz);
		}
	}
public:
	Tabla(int sorok, int oszlopok) : szSorok(sorok), szOszlopok(oszlopok) {
		srand(time(NULL)); // a seed-et 1x allitjuk!
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
		// az osszes babut unfreeze-elni kell, hogy tudjanak mozogni
		for (int sorSz = 0; sorSz < szSorok; sorSz++) {
			for (int oszlopSz = 0; oszlopSz < szOszlopok; oszlopSz++) {
				Babu* cella = tabla[sorSz][oszlopSz];
				if (cella) {
					cella->unfreeze();
				}
			}
		}

		for (int sorSz = 0; sorSz < szSorok; sorSz++) {
			for (int oszlopSz = 0; oszlopSz < szOszlopok; oszlopSz++) {
				Babu* cella = tabla[sorSz][oszlopSz];
				// ha nullptr, vagy le van fagyasztva, nincs mit csinalni! (else ag)
				if (cella && !cella->isStateFrozen()) {
					cellCoords szomszed = getRandomSzomszed(sorSz, oszlopSz);
					
					// ellenorizni kell, hogy nem ugyanott marad!
					if (szomszed.first != sorSz || szomszed.second != oszlopSz) {
						std::cout << cella->char_rep() << " atlepett a (";
						std::cout << szomszed.first << ", " << szomszed.second;
						std::cout << ") mezore!" << std::endl;

						Babu* vedekezo = tabla[szomszed.first][szomszed.second];

						if (vedekezo) {
							// ha van valami ami ott van eppen, akkor megtamadja
							if (cella->megtamad(vedekezo)) {
								tabla[szomszed.first][szomszed.second] = cella;
								tabla[sorSz][oszlopSz] = nullptr;
								cella->freeze();

								std::cout << "\t\t" << vedekezo->char_rep() << " meghalt :(" << std::endl;
								delete vedekezo;
							}
							else {
								std::cout << "\t\t" << cella->char_rep() << " meghalt :(" << std::endl;
								// ha a tamado (aki lep) meghal, nem eleg delete-elni a
								// memoriabol, hanem a tablarol is le kell szedni!
								tabla[sorSz][oszlopSz] = nullptr;
								delete cella;
							}
						}
						else {
							tabla[szomszed.first][szomszed.second] = cella;
							tabla[sorSz][oszlopSz] = nullptr;
							cella->freeze();
						}
					}
				}
			}
		}
		print();
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
		std::cout << "=======" << std::endl << std::endl;
	}
	
};