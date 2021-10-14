#pragma once

#include "kituntetesek.h"

class Katona {
	std::string nev;
	std::string rang;
	int szuletesiEv;
	KituntetesNode* elsoPlecsni;
public:
	//pelda: Katona x("Eros Pista", "Hadnagy", 1977);
	Katona(const std::string& name, const std::string& rank, int yearOfBirth);
	void addPlecsni(const std::string& nev, int year);
	void print();
};
