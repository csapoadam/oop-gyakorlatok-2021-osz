#pragma once

#include <map>
#include <string>

#include "valasztas.h"

class Valaszto;

class ValasztasiJegyzek {
	std::map<int, Valaszto*> valasztok;
	Valasztas valasztas; // ez igy jo??
	std::map<int, bool> hasSzavazott; // minden valasztora
	// megmondja, hogy szavazott-e mar...
public:
	// valasztas tagvaltozot muszaj inicializalni:
	ValasztasiJegyzek() : valasztas("", 0) {}
	void addValaszto(Valaszto* vp);
	void printValasztok();
	void initializeValasztas(Valasztas v) {
		valasztas = v;
		for (auto vIdEsCim : valasztok) {
			// minden valasztora bejegyezni h eddig 0x szavazott
			hasSzavazott[vIdEsCim.first] = false;
		}
	}
	void szavaz(int id, Valasztas& v, int jelolt) {
		// eloszor ellenorizni kene, hogy:
		// - letezik-e ilyen szavazo?
		// - nem szavazott-e mar?
		if (valasztok.find(id) != valasztok.end()) {
			if (!hasSzavazott[id]) {
				v.addSzavazat(jelolt);
				hasSzavazott[id] = true;
			}
		}
	}
};

class Valaszto {
	std::string nev;
	std::string varos;
	int eletkor;
	int azonosito;
public:
	Valaszto(
		const std::string& n,
		const std::string& v,
		int e,
		int id
	) : 
		nev(n), varos(v), eletkor(e), azonosito(id) {}
	int getAzonosito() { return azonosito; }
	std::string getNev() { return nev; }
	std::string getVaros() { return varos; }
	int getEletkor() { return eletkor; }
};