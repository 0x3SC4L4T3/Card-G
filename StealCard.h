#pragma once
#include"Card.h"

class stealCard : public Card {
private:
public:
	stealCard(cardType, string);
	void printCard() override;
	void fileCard(ofstream&) override;
	void setPower(int) override;
	int getPower() override;

};