#include "registry.h"
#include <iostream>

// itt implementalunk sok mindent
void ValasztasiJegyzek::addValaszto(Valaszto* vp) {
	// todo! detektaljuk ha mar benne van!
	valasztok[vp->getAzonosito()] = vp;
}

void ValasztasiJegyzek::printValasztok() {
	std::cout << "Valasztasi jegyzek:" << std::endl;
	for (auto valaszto : valasztok) {
		std::cout << std::string(2, ' ');
		std::cout << valaszto.second->getAzonosito();
		std::cout << ": " << valaszto.second->getNev();
		std::cout << " - " << valaszto.second->getVaros();
		std::cout << " - " << valaszto.second->getEletkor();
		std::cout << std::endl;
	}
}