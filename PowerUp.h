#pragma once
#include"Card.h"

class powerUpCard : public Card{
private:
	int power;
public:
	powerUpCard(cardType, string, int);
	void printCard() override;
	void setPower(int) override;
	void fileCard(ofstream&) override;
	int getPower() override;
};