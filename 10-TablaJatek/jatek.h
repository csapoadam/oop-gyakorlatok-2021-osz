#pragma once
#include "tabla.h"

class Jatek {
	Tabla tabla;
public:
	Jatek(int sorok, int oszlopok) : tabla(sorok, oszlopok) {
		tabla.print();
	}
};