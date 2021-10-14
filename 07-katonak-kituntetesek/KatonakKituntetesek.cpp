// KatonakKituntetesek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "kituntetesek.h"
#include "katonak.h"

#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free

void f() {
	Katona x = Katona("Eros Pista", "Hadnagy", 1977);
	Katona y = Katona("Harcos Helga", "Ezredes", 1979);

	// az addPlecsni() metodus hozza letre a kituntetes objektumokat!
	x.addPlecsni("Arany Akarmi Kereszt", 1997);
	x.addPlecsni("Arany Felso Kereszt", 2002);
	y.addPlecsni("Arany Facan a Legjobb!", 2005);

	Hadsereg h;
	h.addKatona(&x);
	h.addKatona(&y);

	h.print();
}

int main()
{
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld); //take a snapshot

	f();

	_CrtMemCheckpoint(&sNew); //take a snapshot 
	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}

	return 0;
}
