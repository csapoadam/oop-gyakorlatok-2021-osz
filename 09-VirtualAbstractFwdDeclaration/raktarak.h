#pragma once


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