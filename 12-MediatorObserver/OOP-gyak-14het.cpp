// OOP-gyak-14het.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "company.h"
#include "externals.h"
#include "communications.h"

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

	




}
