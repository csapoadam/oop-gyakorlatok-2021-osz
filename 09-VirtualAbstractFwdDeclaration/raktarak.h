#pragma once


class Raktar {
	std::vector<Termek*> termekek;
	std::vector<int> hibatlanDarabszam;
	std::vector<int> hibasDarabszam;
public:
	Raktar& add(TermekCsalad* t, int quantity);
	// addHibas-t csak a Csereszavatos es Garancialis
	// osztalyok javit metodusaban hivjuk meg, de ez is
	// okafogyott, hiszen nem termekcsaladot kell javitani
	// hanem konkret termeket
	void addHibas(Termek* term);
	void kiad(TermekCsalad* term, int db);
	void visszavesz(TermekCsalad* t, int db);
	void print();
};