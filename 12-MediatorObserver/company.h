#pragma once

#include <string>
#include <iostream>

class Mediator;

// 3 osztaly:
// ososztaly: Employee - Ezek mediatorokon keresztul kommunikalnak
// Manager - neve, department (dept. legyen enum class!)
// Coworker - neve, department

enum class Department {
	IT,
	Marketing,
	Design,
	Accounting,
	None
};

class Employee {
	const std::string name;
	Department dept;
public:
	Employee(const std::string& n, Department d) : name(n), dept(d) {}
	void receiveMessage(Employee* sender, std::string msg) {
		std::cout << "\tMessage received by " << name << "from sender " << sender->name;
		std::cout << ":" << std::endl;
		std::cout << "\t\t" << msg << std::endl;
	}
	void sendMessage(Mediator* mp, const std::string& msg);
};

class Manager : public Employee {
public:
	Manager(const std::string& n, Department d) : Employee(n, d) {}
};

class Coworker : public Employee {
public:
	Coworker(const std::string& n, Department d) : Employee(n, d) {}
};

