#include "Card.h"

Card::Card()
{
	this->cardName = "Null";
	this->cardT = None;
}

Card::Card(cardType cT, string name)
{
	this->cardT = cT;
	this->cardName = name;
}

void Card::setType(cardType cT)
{
	this->cardT = cT;
}

void Card::setName(string name)
{
	this->cardName = name;
}

cardType Card::getcardType()
{
	return this->cardT;
}

string Card::getcartName()
{
	return this->cardName;
}
