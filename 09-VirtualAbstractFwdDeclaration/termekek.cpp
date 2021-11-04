#include <iostream>
#include <string>
#include <vector>

#include "termekek.h"
#include "raktarak.h"

TermekCsalad::TermekCsalad(const std::string& nm, int ke)
	: nev(nm), kiadasEve(ke) {}

void TermekCsalad::print() {
	// virtual, mert akar felul is definialhato.
	// DE: nem muszaj feluldefinialni, mivel itt is elvben minden info
	// rendelkezesre all
	std::cout << nev << " (kiadas eve: " << kiadasEve << ")" << std::endl;
}

Garancialis::Garancialis(const std::string nm, int ke) :
	TermekCsalad(nm, ke) {}

void Garancialis::javit(Raktar* rp) {
	std::cout << "A termeket megprobaljuk javitani" << std::endl;
	rp->addHibas(this);
}

Csereszavatos::Csereszavatos(const std::string nm, int ke) :
	TermekCsalad(nm, ke) {}

void Csereszavatos::javit(Raktar* rp) {
	std::cout << "A termek nem javithato, de csereljuk!" << std::endl;
	rp->addHibas(this);
	rp->kiad(this, 1);
}

Laptop::Laptop(const std::string nm, int ke) :
	Garancialis(nm, ke) {}

Mobilkeszulek::Mobilkeszulek(const std::string nm, int ke) :
	Csereszavatos(nm, ke) {}