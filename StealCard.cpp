#include "StealCard.h"

stealCard::stealCard(cardType cT, string name):Card(cT,name)
{
}

void stealCard::printCard()
{
	cout << "Name: " << this->getcartName() << endl;
}

void stealCard::fileCard(ofstream &file)
{
	file << "Name: " << this->getcartName() << endl;
}

void stealCard::setPower(int pow)
{
	return;
}

int stealCard::getPower()
{
	return 0;
}
