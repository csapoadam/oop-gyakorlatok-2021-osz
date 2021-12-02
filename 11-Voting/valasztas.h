#pragma once

class Valasztas {
	std::string nev;
	int jeloltekSzama;
public:
	Valasztas(const std::string& n, int js) :
		nev(n), jeloltekSzama(js) {}
};