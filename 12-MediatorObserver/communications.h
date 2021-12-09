#pragma once

#include <vector>

class Mediator {
	std::vector<Employee*> employees;
public:
	Mediator& addEntity(Employee* ep) { employees.push_back(ep); return *this; }
	void distributeMessage(Employee* sender, std::string msg) {
		for (auto empl : employees) {
			if (empl != sender) {
				empl->receiveMessage(sender, msg);
			}
		}
	}
};