#pragma once
#include <vector>
#include <string>

class Valasztas {
	std::string nev;
	int jeloltekSzama;
	std::vector<int> szavazatok;
public:
	Valasztas(const std::string& n, int js) :
		nev(n), jeloltekSzama(js), szavazatok(js, 0) {}

	void addSzavazat(int jelolt) {
		if (jelolt < jeloltekSzama) {
			szavazatok[jelolt] += 1;
		}
	}
};