#pragma once


class Raktar {
	std::vector<TermekCsalad*> termekek;
	std::vector<int> hibatlanDarabszam;
	std::vector<int> hibasDarabszam;
public:
	Raktar& add(TermekCsalad* t, int quantity);
	void addHibas(TermekCsalad* term);
	void kiad(TermekCsalad* term, int db);
	void visszavesz(TermekCsalad* t, int db);
	void print();
};