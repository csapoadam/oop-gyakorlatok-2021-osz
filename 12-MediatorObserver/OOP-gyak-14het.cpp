// OOP-gyak-14het.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "communications.h"
#include "company.h"
#include "externals.h"


int main()
{
	Auditor auditor0("Auditor Bela");

	Manager manager0("Menedzser Mark", Department::IT);
	Coworker coworker0("Magnus Sorensen", Department::IT);
	Coworker coworker1("Markus Eva", Department::Marketing);

	Mediator allemployees;
	allemployees.addEntity(&manager0).addEntity(&coworker0).addEntity(&coworker1);
	
	Mediator itdept;
	itdept.addEntity(&manager0).addEntity(&coworker0);

	manager0.sendMessage(&allemployees, "Hello everyone! Welcome to Company X!");
	coworker1.sendMessage(&itdept, "Hello, dinner at my place?");
	auditor0.sendMessage(&allemployees, "Reszkessetek tolem!");

}
