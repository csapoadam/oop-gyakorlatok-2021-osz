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
		// itt vegig iteralunk a positions argumentumon
		// es mindegyik cellaba berakjuk az adott tipusu babut
		tabla.print();
	}
};