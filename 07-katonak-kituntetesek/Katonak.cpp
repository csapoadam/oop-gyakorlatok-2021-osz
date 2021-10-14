#include "katonak.h"

Katona::Katona(const std::string& name, const std::string& rank, int yearOfBirth) :
	nev(name), rang(rank), szuletesiEv(yearOfBirth), elsoPlecsni(nullptr) {
}

void Katona::addPlecsni(const std::string& nev, int year) {
	KituntetesNode* newnode = new KituntetesNode(nev, year);
	if (!elsoPlecsni) {
		elsoPlecsni = newnode;
	}
	else {
		KituntetesNode* candidateLastNode = elsoPlecsni;
		while (true) {
			bool success = candidateLastNode->append(newnode);
			if (success) {
				break;
			}
			candidateLastNode = candidateLastNode->getNext();
		}
	}
}

void Katona::print() {
	std::cout << "\t" << nev << " (" << rang << " - " << szuletesiEv << ")";
	std::cout << std::endl;

	KituntetesNode* candidateLastNode = elsoPlecsni;
	while (candidateLastNode) {
		candidateLastNode->print();
		candidateLastNode = candidateLastNode->getNext();
	}
	// itt meg a plecsniket ki kell iratni!
}