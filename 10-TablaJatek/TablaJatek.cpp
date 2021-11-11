// TablaJatek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "jatek.h"

int main()
{
	//// std::vector egyik konstruktora:
	//// 5 elemu vektor csupa 1-essel:
	//std::vector<int> egyesek(5, 1);
	//for (auto elem : egyesek) {
	//	std::cout << elem << ", ";
	//}

	BabuPositions positions;
	positions[std::make_pair<int, int>(3, 4)] = BabuTypes::Aligator;
	positions[std::make_pair<int, int>(1, 7)] = BabuTypes::Csirke;

	Jatek j(7, 10, positions);
}
