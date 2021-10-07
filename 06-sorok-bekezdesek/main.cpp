// SorokEsBekezdesek2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class Szo {
	const std::string content;
public:
	Szo(const std::string& szo) : content(szo) {}
	int getLength() const { return content.length(); }
	void print() { std::cout << content; }
};

class Sor {
	std::vector<Szo> szavak;
	int currentHossz;
	const int hosszLimit;
public:
	Sor() : currentHossz(0), hosszLimit(10) {}
	bool addSzo(const Szo& sz) {
		if (currentHossz < hosszLimit) {
			if (szavak.size() > 0) { currentHossz++; }
			currentHossz = currentHossz + sz.getLength();
			szavak.push_back(sz);
			return true;
		}
		return false;
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

class Bekezdes {
	std::vector<Sor> sorok;
public:
	void addText(const std::string& text) {
		int inxOfNextSpace = 0;
		int inxOfPreviousSpace = -1;
		bool stop = false;

		while (!stop) {
			inxOfNextSpace = text.find(" ", inxOfPreviousSpace + 1);
			std::string nextSzo = text.substr(inxOfPreviousSpace + 1,
				inxOfNextSpace - inxOfPreviousSpace - 1);
			inxOfPreviousSpace = inxOfNextSpace;

			if (nextSzo == "" || inxOfNextSpace == -1) {
				stop = true;
			}
			if (nextSzo.length() > 0) {
				// adjuk hozza az utolso sorhoz!!
				std::cout << "hozzaadva!" << std::endl;
			}
			std::cout << "kovetkezo szo: ." << nextSzo << "." << std::endl;
		}
	}
	void print() {}
};

int main()
{
	Bekezdes b;
	b.addText("This is a test szoveg.");
	b.addText("Please, please add this text and do not forget to create new lines in the process.");
	b.addText("Keep going with creating new lines as long as the previous line has more than 75 characters");
	b.print();
}
