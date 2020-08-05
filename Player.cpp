#include "Player.h"

Player::Player(string pName)
{
	this->playerName = pName;
	this->powerScore = 0;
	this->board = new Card*[5];
	this->boardIndex = 0;
}

Player::~Player()
{
	if (board != nullptr) {
		for (int i = 0; i < 5; i++) {
			delete board[i];
		}

		delete[]board;
	}
}

void Player::insertCard(Card *c)
{
	if (boardIndex < 5) {
		board[boardIndex] = c;
		boardIndex++;
	}
	else
	{
		cout << "Board already Full\n";
	}

}

void Player::removeCard(Card *cT)
{
	int i;
	for (i = 0; i < boardIndex; i++) {
		if (board[i] == cT) {
			break;
		}
	}

	if (i < boardIndex) {
		boardIndex = boardIndex - 1;
		for (int j = i; j < boardIndex; j++) {
			board[j] = board[j + 1];
		}
	}
}

void Player::printPlayer()
{
	cout << "Player Name: " << this->playerName << "\n";
	cout << "Power Score = " << this->powerScore << endl;
	cout << "Player Cards: \n";
	for (int i = 0; i < boardIndex; i++) {
		board[i]->printCard();
	}
}

Card * Player::getCardfromDeck(int ind)
{
	if (ind < 5) {
		return board[ind];
	}
	return nullptr;
}

void Player::reduceScore(int s)
{
	powerScore -= s;
}

void Player::increaseScore(int s)
{
	powerScore += s;
}

int Player::getboardIndex()
{
	return boardIndex;
}

int Player::getScore()
{
	return powerScore;
}

void Player::filePlayer(ofstream &file)
{

	file << "Player Name: " << this->playerName << "\n";
	file << "Power Score = " << this->powerScore << endl;
	file << "Player Cards: \n";
	for (int i = 0; i < boardIndex; i++) {
		board[i]->fileCard(file);
	}
}
