#include "powerDown.h"

powerDownCard::powerDownCard(cardType cT, string name, int pow): Card(cT,name)
{
	this->power = pow;
}

void powerDownCard::printCard()
{
	cout << "Name: " << this->getcartName() << " ";
	cout << "[Power = " << this->power << "]" << endl;
}

void powerDownCard::fileCard(ofstream &file)
{
	file << "Name: " << this->getcartName() << " ";
	file << "[Power = " << this->power << "]" << endl;
}


void powerDownCard::setPower(int pow)
{
	this->power = pow;
}

int powerDownCard::getPower()
{
	return this->power;
}
