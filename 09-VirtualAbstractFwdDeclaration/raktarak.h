#pragma once


class Raktar {
	std::vector<Termek*> termekek;
	std::vector<int> hibatlanDarabszam;
	std::vector<int> hibasDarabszam;
public:
	Raktar& add(Termek* t, int quantity);
	void addHibas(Termek* term);
	void kiad(Termek* term, int db);
	void visszavesz(Termek* t, int db);
	void print();
};