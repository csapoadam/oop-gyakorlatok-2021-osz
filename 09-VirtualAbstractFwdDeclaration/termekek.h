#pragma once
#include <iostream>
#include <string>
#include <vector>

class Raktar; // forward deklaracio!
// ez azert fontos, mert a Termek interfesze (javit(Raktar*)) hivatkozik
// a Raktar tipusra, de a fordito nem tudja hogy ilyen tipus letezik!
// itt viszont nem lehet kifejteni a Raktar osztalyt, mert abban lesznek
// Termek*-ok is, mivel egy vektorban tarolnia kell a Termekek cimeit

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

class Garancialis : public Termek {
public:
	Garancialis(const std::string nm, int ke) :
		Termek(nm, ke) {}
	void javit(Raktar* rp) override; // kulon
	// cpp file-ban kell definialni, mert rp
	// metodusai itt nem ismertek
};

class Csereszavatos : public Termek {
public:
	Csereszavatos(const std::string nm, int ke) :
		Termek(nm, ke) {}
	void javit(Raktar* rp) override; // ezt is
	// kulon cpp file-ban kell definialni
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