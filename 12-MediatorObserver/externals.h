#pragma once

#include <string>

// Auditor (revizor) - nevvel rendelkezik - ez egyfajta observer lesz

class Auditor {
	const std::string name;
public:
	Auditor(const std::string& n) : name(n) {}
};