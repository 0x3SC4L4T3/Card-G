#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum cardType{powerUp,powerDown,steal,None};

class Card {
private:
	cardType cardT;
	string cardName;
public:
	Card();
	Card(cardType, string);
	virtual void printCard() = 0;
	virtual void fileCard(ofstream&) = 0;
	virtual int getPower() = 0;
	virtual void setPower(int) = 0;
	void setType(cardType);
	void setName(string);
	cardType getcardType();
	string getcartName();
};
