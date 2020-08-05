#include "PowerUp.h"

powerUpCard::powerUpCard(cardType cT, string name, int pow) : Card(cT,name)
{
	this->power = pow;
}

void powerUpCard::printCard() 
{
	cout << "Name: " << this->getcartName() << " ";
	cout << "[Power = " << this->power << "]" << endl;
}

void powerUpCard::fileCard(ofstream &file)
{
	file << "Name: " << this->getcartName() << " ";
	file << "[Power = " << this->power << "]" << endl;
}

void powerUpCard::setPower(int pow)
{
	this->power = pow;
}

int powerUpCard::getPower()
{
	return power;
}
