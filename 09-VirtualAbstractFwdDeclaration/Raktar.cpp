// Raktar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Raktar osztaly:
// Termek tipusu pointereket tarol el
// Termek legyen absztrakt osztaly!
// mindegyik termekhez szamon tart mennyiseget
// A termek lehet garancialis v. csereszavatos (csere garancialis?)
// ezen belul legyen TV, Mobiltelefon, Laptop
// minden termek "tudja", hogy melyik
// ... raktarbol szarmazik
// igy ha a termeket "visszakuldik", ez megteheto


#include <iostream>

#include "termekek.h"

int main()
{
    Raktar r;
    Laptop l1("ASUS TUF Gaming", 2020, 5);
    Laptop l2("Lenovo Legion Y520", 2018, 3);
    Mobilkeszulek m1("Xperia Hypersuper", 2019, 4);
    r.add(&l1).add(&l2).add(&m1);
    r.print();
    l1.javit(&r);
    l2.javit(&r);
    m1.javit(&r);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
