#include "cardFactory.h"

cardFactory::cardFactory(cardType cT)
{
	if (cT == powerUp) {
		int pow = rand() % (5 - 1 + 1) + 1;
		this->factoryCard = new powerUpCard(powerUp, "Power+", pow);
	}

	if (cT == powerDown) {
		int pow = rand() % 5 + 1;
		this->factoryCard = new powerDownCard(powerDown, "Power-", pow);
	}

	if (cT == steal) {
		this->factoryCard = new stealCard(steal, "Steal");
	}
}

Card * cardFactory::getCard()
{
	return this->factoryCard;
}

cardFactory::~cardFactory()
{
	if (this->factoryCard != nullptr) {
		delete factoryCard;
	}
}
