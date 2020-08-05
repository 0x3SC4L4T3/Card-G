#pragma once
#include "powerDown.h"
#include "PowerUp.h"
#include "StealCard.h"


class cardFactory {
private:
	Card *factoryCard;
public:
	cardFactory(cardType);
	Card *getCard();
	~cardFactory();
};