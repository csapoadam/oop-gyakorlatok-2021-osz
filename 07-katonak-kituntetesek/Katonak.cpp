#include "katonak.h"

Katona::Katona(const std::string& name, const std::string& rank, int yearOfBirth) :
	nev(name), rang(rank), szuletesiEv(yearOfBirth), elsoPlecsni(nullptr) {
}

void Katona::addPlecsni(const std::string& nev, int year) {
	KituntetesNode* newnode = new KituntetesNode(nev, year);
	if (!elsoPlecsni) {
		elsoPlecsni = newnode;
	}
}

void Katona::print() {
	std::cout << "\t" << nev << " (" << rang << " - " << szuletesiEv << ")";
	std::cout << std::endl;
	if (elsoPlecsni) {
		elsoPlecsni->print();
	}
	// itt meg a plecsniket ki kell iratni!
}