#pragma once

enum class BabuTypes {
	Aligator,
	Csirke,
	Ember
};

// ez lesz az abstract base class, amibol tobbfele Babu szarmazhat
class Babu {
public:
	virtual char char_rep() = 0;
};

class Aligator : public Babu {
public:
	char char_rep() override {
		return 'A';
	}
};

class Csirke : public Babu {
public:
	char char_rep() override {
		return 'C';
	}
};

class Ember : public Babu {
public:
	char char_rep() override {
		return 'E';
	}
};