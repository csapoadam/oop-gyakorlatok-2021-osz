// SorokEsBekezdesek2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class Szo {
	const std::string content;
public:
	Szo(const std::string& szo) : content(szo) {}
	int getLength() { return content.length(); }
	void print() { std::cout << content; }
};

class Sor {
	std::vector<Szo> szavak;
public:
	void addSzo(const Szo& sz) {
		szavak.push_back(sz);
	}
	void print() {
		bool isFirst = true;
		for (Szo sz : szavak) {
			if (!isFirst) { std::cout << " "; }
			else { isFirst = false; }
			sz.print();
		}
		std::cout << std::endl;
	}
};

class Bekezdes {};

int main()
{
	Szo v1("valami");
	Szo v2("furcsa");
	Szo v3("es");
	Szo v4("megmagyarazhatatlan");
	
	Sor sor1;
	sor1.addSzo(v1);
	sor1.addSzo(v2);
	sor1.addSzo(v3);
	sor1.addSzo(v4);
	sor1.print();
	/*Bekezdes b;
	b.addText("This is a test szoveg.");
	b.addText("Please, please add this text and do not forget to create new lines in the process.");
	b.addText("Keep going with creating new lines as long as the previous line has more than 75 characters");
	b.print();*/
}
