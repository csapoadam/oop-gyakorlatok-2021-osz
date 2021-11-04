#include <iostream>
#include <string>
#include <vector>

#include "termekek.h"
#include "raktarak.h"

Raktar& Raktar::add(Termek* t, int quantity) {
	termekek.push_back(t);
	hibatlanDarabszam.push_back(quantity);
	hibasDarabszam.push_back(0);
	return *this;
}

void Raktar::addHibas(Termek* term) {
	int cnt = 0;
	for (Termek* t : termekek) {
		if (t == term) {
			hibasDarabszam[cnt] += 1;
		}
		cnt++;
	}
}

void Raktar::kiad(Termek* term, int db) {
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

void Raktar::visszavesz(Termek* t, int db) {
	for (int i = 0; i < db; i++) {
		t->javit(this);
	}
}

void Raktar::print() {
	int cnt = 0;
	for (Termek* t : termekek) {
		t->print();
		std::cout << "\tHibatlan db: " <<
			hibatlanDarabszam[cnt] << ", Hibas db: " <<
			hibasDarabszam[cnt] << std::endl;
		cnt++;
	}
}