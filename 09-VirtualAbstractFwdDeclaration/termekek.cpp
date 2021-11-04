#include "termekek.h"
#include "raktarak.h"

void Garancialis::javit(Raktar* rp) {
	std::cout << "A termeket megprobaljuk javitani" << std::endl;
	rp->addHibas(this);
}

void Csereszavatos::javit(Raktar* rp) {
	std::cout << "A termek nem javithato, de csereljuk!" << std::endl;
	rp->addHibas(this);
	rp->kiad(this, 1);
}