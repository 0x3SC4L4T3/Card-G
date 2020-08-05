#pragma once
#include"Card.h"

class powerDownCard : public Card {
private:
	int power;
public:
	powerDownCard(cardType, string, int);
	void printCard() override;
	void setPower(int) override;
	void fileCard(ofstream&) override;
	int getPower() override;
};