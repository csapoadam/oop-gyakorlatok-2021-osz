#pragma once
#include <iostream>

class Kituntetes {
	std::string nev;
	int evszam;
public:
	Kituntetes(const std::string& name, int year) :
		nev(name), evszam(year)
	{}
	void print() {
		std::cout << "\tKituntetes: " << nev << " ("
			<< evszam << ")" << std::endl;
	}
};