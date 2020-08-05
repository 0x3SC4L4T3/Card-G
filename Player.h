#pragma once
#include "Card.h"
#include <vector>
class Player{
private:
	string playerName;
	int powerScore;
	Card **board;
	int boardIndex;
public:
	Player(string);
	~Player();
	void insertCard(Card *);
	void removeCard(Card *);
	void printPlayer();
	Card *getCardfromDeck(int);
	void reduceScore(int);
	void increaseScore(int);
	int getboardIndex();
	int getScore();
	void filePlayer(ofstream&);
};
