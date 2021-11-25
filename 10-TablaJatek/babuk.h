#pragma once

enum class BabuTypes {
	Aligator,
	Csirke,
	Ember
};

// ez lesz az abstract base class, amibol tobbfele Babu szarmazhat
class Babu {
	bool isFrozen;
public:
	Babu() : isFrozen(false) {}
	virtual char char_rep() = 0;
	void freeze() { isFrozen = true; }
	void unfreeze() { isFrozen = false; }
	bool isStateFrozen() { return isFrozen; }
	virtual double getTamadoEro() = 0;
	virtual double getVedekezoEro() = 0;
	bool megtamad(Babu* vedekezo) {
		// akkor igaz, ha a tamado nyer; kulonben hamis
		std::cout << "\t" << char_rep() << " megtamadta " << vedekezo->char_rep();
		std::cout << "-t ... hajjaj!" << std::endl;
		return this->getTamadoEro() > vedekezo->getVedekezoEro();
	}
};

class Aligator : public Babu {
public:
	char char_rep() override {
		return 'A';
	}
	double getTamadoEro() { return 0.8; }
	double getVedekezoEro() { return 0.6; }
};

class Csirke : public Babu {
public:
	char char_rep() override {
		return 'C';
	}
	double getTamadoEro() { return 0.2; }
	double getVedekezoEro() { return 0.2; }
};

class Ember : public Babu {
public:
	char char_rep() override {
		return 'E';
	}
	double getTamadoEro() { return 0.8; }
	double getVedekezoEro() { return 0.7; }
};