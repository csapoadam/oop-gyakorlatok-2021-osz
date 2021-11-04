#include <iostream>
#include <string>
#include <vector>

#include "termekek.h"
#include "raktarak.h"

Raktar& Raktar::add(TermekCsalad* t, int quantity) {
	for (int i = 0; i < quantity; i++) {
		termekek.push_back(new Termek(t));
		// massziv TODO!:
		// innentol kezdve majd a deleterol se felejtkezzunk el!
		hibatlanDarabszam.push_back(1); // ez itt hulyen nez ki
		// de majd refaktoraljuk...
		hibasDarabszam.push_back(0);
	}
	return *this;
}

void Raktar::addHibas(Termek* term) {
	int cnt = 0;
	for (Termek* t : termekek) {
		if (t == term) {
			hibasDarabszam[cnt] = 1;
			hibatlanDarabszam[cnt] = 0;
			t->visszavesz();
		}
		cnt++;
	}
}

void Raktar::kiad(TermekCsalad* term, int db) {
	int cnt = 0;
	int numTermeksKiadva = 0;
	for (Termek* t : termekek) {
		if (t->getTipus() == term &&
			t->isKiadhato() &&
			hibatlanDarabszam[cnt] > 0
			// ez utobbi botranyos most mar, 
			// ezt is a Termek osztalynak kene
			// menedzselnie
			) {
			t->kiad();
			numTermeksKiadva++;
			if (numTermeksKiadva == db) {
				return;
			}
		}
		cnt++;
	}
}

void Raktar::visszavesz(TermekCsalad* tc, int db) {
	int cnt = 0;
	int numTermeksVisszaveve = 0;
	for (Termek* t : termekek) {
		if (t->getTipus() == tc &&
			!t->isKiadhato()
			) {
			hibatlanDarabszam[cnt] = 0;
			hibasDarabszam[cnt] = 1;
			t->javit(this);
			numTermeksVisszaveve++;
			if (numTermeksVisszaveve == db) {
				return;
			}
		}
		cnt++;
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