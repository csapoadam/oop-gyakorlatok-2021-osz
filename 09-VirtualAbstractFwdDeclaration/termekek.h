#pragma once
#include <iostream>
#include <string>
#include <vector>

class Raktar; // forward deklaracio!
// ez azert fontos, mert a Termek interfesze (javit(Raktar*)) hivatkozik
// a Raktar tipusra, de a fordito nem tudja hogy ilyen tipus letezik!
// itt viszont nem lehet kifejteni a Raktar osztalyt, mert abban lesznek
// Termek*-ok is, mivel egy vektorban tarolnia kell a Termekek cimeit

// termeknek legyen:
// neve
// kiadasEve
class Termek {
	std::string nev;
	int kiadasEve;
public:
	Termek(const std::string& nm, int ke)
		: nev(nm), kiadasEve(ke) {}
	virtual void print() {
		// virtual, mert akar felul is definialhato.
		// DE: nem muszaj feluldefinialni, mivel itt is elvben minden info
		// rendelkezesre all
		std::cout << nev << " (kiadas eve: " << kiadasEve << ")" << std::endl;
	}
	virtual void javit(Raktar*) = 0; // pure virtual method! -> abstract class
	// ezt, hogy javit() itt nem tudjuk definialni, mert nem tudjuk, hogy
	// javithato-e a termek (garancialis? vagy cserelik rogton?)
};

class Raktar {
	std::vector<Termek*> termekek;
	std::vector<int> hibatlanDarabszam;
	std::vector<int> hibasDarabszam;
public:
	Raktar& add(Termek* t, int quantity) {
		termekek.push_back(t);
		hibatlanDarabszam.push_back(quantity);
		hibasDarabszam.push_back(0);
		return *this;
	}
	void addHibas(Termek* term) {
		int cnt = 0;
		for (Termek* t : termekek) {
			if (t == term) {
				hibasDarabszam[cnt] += 1;
			}
			cnt++;
		}
	}
	void kiad(Termek* term, int db) {
		int cnt = 0;
		for (Termek* t : termekek) {
			if (t == term) {
				if (hibatlanDarabszam[cnt] < db) {
					std::cout << "nincsen ennyi darab!";
					hibatlanDarabszam[cnt] = 0;
				}
				else {
					hibatlanDarabszam[cnt] = hibatlanDarabszam[cnt] - db;
				}
			}
			cnt++;
		}
	}
	void visszavesz(Termek* t, int db) {
		for (int i = 0; i < db; i++) {
			t->javit(this);
		}
	}
	void print() {
		int cnt = 0;
		for (Termek* t : termekek) {
			t->print();
			std::cout << "\tHibatlan db: " <<
				hibatlanDarabszam[cnt] << ", Hibas db: " <<
				hibasDarabszam[cnt] << std::endl;
			cnt++;
		}
	}
};

class Garancialis : public Termek {
public:
	Garancialis(const std::string nm, int ke) :
		Termek(nm, ke) {}
	void javit(Raktar* rp) override {
		std::cout << "A termeket megprobaljuk javitani" << std::endl;
		rp->addHibas(this);
	}
};

class Csereszavatos : public Termek {
public:
	Csereszavatos(const std::string nm, int ke) :
		Termek(nm, ke) {}
	void javit(Raktar* rp) override {
		std::cout << "A termek nem javithato, de csereljuk!" << std::endl;
		rp->addHibas(this);
		rp->kiad(this, 1);
	}
};

class Laptop : public Garancialis {
public:
	Laptop(const std::string nm, int ke) :
		Garancialis(nm, ke) {}
};

class Mobilkeszulek : public Csereszavatos {
public:
	Mobilkeszulek(const std::string nm, int ke) :
		Csereszavatos(nm, ke) {}
};