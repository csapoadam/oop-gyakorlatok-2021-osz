#pragma once
#include <map>
#include "tabla.h"

typedef std::map<std::pair<int, int>, BabuTypes> BabuPositions;

class Jatek {
	Tabla tabla;
public:
	Jatek(
		int sorok,
		int oszlopok,
		BabuPositions positions
	) : tabla(sorok, oszlopok) {
		// feladat1:
		// itt vegig iteralunk a positions argumentumon
		// es mindegyik cellaba berakjuk az adott tipusu babut
		// ehhez keszitsunk egy Tabla::createBabu() metodust!
		for (auto p : positions) {
			int coordx = p.first.first;
			int coordy = p.first.second;
			BabuTypes bt = p.second;
			tabla.createBabu(coordx, coordy, bt);
		}
		tabla.print();
	}
};