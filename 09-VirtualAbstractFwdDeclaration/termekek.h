#pragma once
#include <iostream>
#include <string>
#include <vector>

class Raktar; // forward deklaracio!
// ez azert fontos, mert a Termek interfesze (javit()) hivatkozik
// a Raktar tipusra, de a fordito nem tudja hogy ilyen tipus letezik!
// itt viszont nem lehet kifejteni a Raktar osztalyt, mert abban lesznek
// Termek*-ok is, mivel egy vektorban tarolnia kell a Termekek cimeit

// termeknek legyen:
// neve
// elettartama (evekben merve)
// gyartasi eve 
// ha az elettartam letelik, minden evben 50% esellyel
// elromlik
// legyen benne egy flag, hogy elromlott 
class Termek {
	std::string nev;
	int elettartam;
	int gyartasiEv;
	bool elromlott;
public:
	Termek(const std::string& nm, int ge, int et)
		: nev(nm), elettartam(et), gyartasiEv(ge), elromlott(false) {}
	virtual void print() {
		// virtual, mert akar felul is definialhato.
		// DE: nem muszaj feluldefinialni, mivel itt is elvben minden info
		// rendelkezesre all
		std::cout << nev << " (gyartas eve: " << gyartasiEv << "), elromlott?" << elromlott << std::endl;
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
	Garancialis(const std::string nm, int gyartasiev, int elettartam) :
		Termek(nm, gyartasiev, elettartam) {}
	void javit(Raktar*) override {
		std::cout << "A termeket megprobaljuk javitani" << std::endl;
	}
};

class Csereszavatos : public Termek {
public:
	Csereszavatos(const std::string nm, int gyartasiev, int elettartam) :
		Termek(nm, gyartasiev, elettartam) {}
	void javit(Raktar*) override {
		std::cout << "A termek nem javithato, de csereljuk!" << std::endl;
	}
};

class Laptop : public Garancialis {
public:
	Laptop(const std::string nm, int gyartasiev, int elettartam) :
		Garancialis(nm, gyartasiev, elettartam) {}
};

class Mobilkeszulek : public Csereszavatos {
public:
	Mobilkeszulek(const std::string nm, int gyartasiev, int elettartam) :
		Csereszavatos(nm, gyartasiev, elettartam) {}
};