#pragma once

class Valaszto;

class ValasztasiJegyzek {
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
};