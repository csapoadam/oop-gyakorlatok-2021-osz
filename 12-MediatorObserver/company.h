#pragma once

#include <string>

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
};

class Manager : public Employee {
public:
	Manager(const std::string& n, Department d) : Employee(n, d) {}
};

class Coworker : public Employee {
public:
	Coworker(const std::string& n, Department d) : Employee(n, d) {}
};

