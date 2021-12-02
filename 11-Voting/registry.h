#pragma once

#include <map>
#include <string>

class Valaszto;

class ValasztasiJegyzek {
	std::map<int, Valaszto*> valasztok;
public:
	void addValaszto(Valaszto* vp);
	void printValasztok();
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