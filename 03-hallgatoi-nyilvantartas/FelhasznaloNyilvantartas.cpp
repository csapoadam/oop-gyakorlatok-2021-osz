// FelhasznaloNyilvantartas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// Targy
//// targy kodja: string
//// targy neve: string
//// kreditszam: int

class Targy {
    std::string kod;
    std::string nev;
    int kredit;
public:
    // konstruktor
    Targy(std::string kod, std::string nv, int kr) {
        nev = nv; this->kod = kod; kredit = kr;
    }
    // print metodus
    void print() {
        std::cout << nev << " (" << kod << ") - " << kredit << " kredit" << std::endl;
    }
};

// Hallgato
//// nev: string
//// neptun kod: string
//// valamilyen tarolo, hogy milyen targyakat vett fel
class Hallgato {
    std::string nev;
    std::string neptun;
    Targy* targyak[100];
    int felvettTargyakSzama;
public:
    // konstruktor
    Hallgato(std::string nv, std::string nkod) {
        nev = nv; neptun = nkod; felvettTargyakSzama = 0;
    }
    // addTargy
    void addTargy(Targy* tp) {
        if (felvettTargyakSzama < 100) {
            targyak[felvettTargyakSzama] = tp;
            felvettTargyakSzama++;
        }
    }
    // print
    void print() {
        std::cout << nev << " (neptun: " << neptun << "):" << std::endl;
        for (int i = 0; i < felvettTargyakSzama; i++) {
            std::cout << "\t";
            targyak[i]->print();
        } 
    }
};

// HallgatoDb
///// valamilyen tarolo, a hallgatok reszere

int main()
{
    Targy t1("NKNB-INTM024", "C++ programozas", 5);
    Targy t2("NKLB-INTM083", "Szoftverteszteles", 3);
    t1.print(); t2.print();

    Hallgato h1("Szucs Imre", "OKER3X");
    Hallgato h2("Nagy Eva", "KEJEE6");
    h1.addTargy(&t1); h1.addTargy(&t2);
    h2.addTargy(&t2);
    h1.print(); h2.print();
}
