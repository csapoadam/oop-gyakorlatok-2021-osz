#include "katonak.h"

Katona::Katona(const std::string& name, const std::string& rank, int yearOfBirth) :
	nev(name), rang(rank), szuletesiEv(yearOfBirth) {
}

void Katona::addPlecsni(const std::string& nev, int year) {}

void Katona::print() {
	std::cout << "\t" << nev << " (" << rang << " - " << szuletesiEv << ")";
	std::cout << std::endl;
	// itt meg a plecsniket ki kell iratni!
}