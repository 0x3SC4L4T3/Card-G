#include "Card.h"
#include "Player.h"
#include "cardFactory.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>

int main() {

	vector <Card*> cardDeck;
	cardFactory *CardGenerator;
	ofstream myfile;
	myfile.open("GameLog.txt");

	if (!myfile.is_open()) {
		cout << "File error , cannot play the game without database\n";
		return 0;
	}

	int randomCard;
	cardType cT = None;
	int iter = 0;
	srand((unsigned int)time(NULL));
	do {
		randomCard = rand() % (3 - 1 + 1) + 1;
		if (randomCard == 1) {
			cT = powerUp;
		}

		if (randomCard == 2) {
			cT = powerDown;
		}

		if (randomCard == 3) {
			cT = steal;
		}
			
		CardGenerator = new cardFactory(cT);

		cardDeck.push_back(CardGenerator->getCard());
		iter++;
	} while (iter != 20);


	cout << "\n******************************Card Deck Generated**************************** \n\n";
	int cardId = 0;
	for (unsigned int i = 0; i < cardDeck.size(); i++) {
		cout << "Card Id: " << cardId << " ";
		cardDeck[i]->printCard();
		cardId++;
	}

	cout << "\n****************************************************************************** \n\n";


	Player *Player1= new Player("Player1");
	Player *Player2 = new Player("Virtual Player");

	int cardIndex[20];

	for (int i = 0; i < 20; i++) {
		cardIndex[i] = 0;
	}

	cout << "Virtual Player has selected its cards\n";

	
	int cNo = 0;

	int virtualCardCount = 5;
	int playerCardCount = 5;

	while (virtualCardCount != 0) {

		cNo = rand() % (19 - 0 + 1) + 0;
		if (cardIndex[cNo] == 0) {
			cardIndex[cNo] = 1;
			Player2->insertCard(cardDeck.at(cNo));
			virtualCardCount--;
		}		
	}

	Player2->printPlayer();

	cout << "\n*******************************Remaining Deck********************************* \n\n";


	for (int i = 0; i < 20; i++) {
		if (cardIndex[i] == 0) {
			cout << "Card Id: " << i << " ";
			cardDeck[i]->printCard();
		}
	}

	cout << "\n****************************************************************************** \n\n";


	cout << "\nPlayer 1 , Please choose 5 cards: \n";


	while (playerCardCount != 0) {

		cout << "Enter Card Index: ";
		cin >> cNo;
		if (cardIndex[cNo] == 0) {
			cardIndex[cNo] = 1;
			Player1->insertCard(cardDeck.at(cNo));
			playerCardCount--;
		}
		else {
			cout << "Card not Available\n";
		}
	}


	Player1->printPlayer();

	cout << "\n****************************************************************************** \n\n";


	cout << "Brace yourself ! The game will be starting in 2 seconds: ";
	Sleep(5000);

	system("cls");

	int turn = 1;

	while (true) {

		if (Player1->getboardIndex() == 0 && Player2->getboardIndex() == 0) {
			
			Player1->printPlayer();
			Player2->printPlayer();
			if (Player1->getScore() > Player2->getScore()) {
				cout << "Congratulations! You win the game\n";
				myfile << "Congratulations! You win the game\n";
			}
			if (Player2->getScore() > Player1->getScore()) {
				cout << "Congratulations! Virtual Player win the game\n";
				myfile << "Congratulations! Virtual Player win the game\n";
			}

			if (Player2->getScore() == Player1->getScore()) {
				cout << "Match is Draw\n";
				myfile << "Match is Draw\n";
			}

			break;
		}

		if (turn == 1) {
			Player2->printPlayer();
			Player2->filePlayer(myfile);
			cout << "Your Turn: \n";
			cout << "Enter Card Number from your Deck: ";
			if (Player2->getboardIndex() == 0) {
				myfile << "You Board is empty, Your turn has been skipped\n";
				cout << "You Board is empty, Your turn has been skipped\n";
				turn = 2;
				continue;
			}
			cNo = rand() % Player2->getboardIndex();
			cout << cNo << endl;

			Card *c = Player2->getCardfromDeck(cNo);
			if (c == NULL) {
				cout << "Invalid choice";
				while (c == NULL) {
					cout << "Enter valid choice of card: ";
					cNo = rand() % Player2->getboardIndex();
					cout << cNo << endl;
					Card *c = Player2->getCardfromDeck(cNo);
				}
			}

			if (c->getcardType() == powerDown) {
				cout << "Card Played: ";
				myfile << "Card Played: ";
				c->printCard();
				c->fileCard(myfile);
				Player1->reduceScore(c->getPower());
				Player2->removeCard(c);
				Player2->printPlayer();
				Player2->filePlayer(myfile);
			}

			if (c->getcardType() == powerUp) {
				cout << "Card Played: ";
				c->printCard();
				Player2->increaseScore(c->getPower());
				Player2->removeCard(c);
				Player2->printPlayer();
			}

			if (c->getcardType() == steal) {
				cout << "Card Played: ";
				myfile << "Card Played: ";
				c->printCard();
				c->fileCard(myfile);
				Player2->removeCard(c);
				
				if (Player1->getboardIndex() == 0) {
						CardGenerator = new cardFactory(powerUp);
						c = CardGenerator->getCard();
						c->setPower(1);
						Player2->insertCard(c);
						Player1->removeCard(c);
						Player2->printPlayer();
						Player2->filePlayer(myfile);
				}
				else {
					cNo = rand() % Player1->getboardIndex();
					Card *c = Player1->getCardfromDeck(cNo);
					if (c == NULL) {
						CardGenerator = new cardFactory(powerUp);
						c = CardGenerator->getCard();
						c->setPower(1);
						Player2->insertCard(c);
						Player1->removeCard(c);
						Player2->printPlayer();
						Player2->filePlayer(myfile);
					}
					else {
						Player2->insertCard(c);
						Player1->removeCard(c);
						Player2->printPlayer();
						Player2->filePlayer(myfile);
					}

				}


			}


			turn = 2;
			cout << "\n****************************************************************************** \n\n";
			myfile << "\n****************************************************************************** \n\n";
		}

		if (turn == 2) {
			Player1->printPlayer();
			Player1->filePlayer(myfile);

			if (Player1->getboardIndex() == 0) {
				cout << "Your Board is empty, Your turn has been skipped\n";
				cout << "You Board is empty, Your turn has been skipped\n";
				turn = 1;
				continue;
			}

			cout << "Your Turn: \n";
			cout << "Enter Card Number from your Deck: ";
			cin >> cNo;

			Card *c = Player1->getCardfromDeck(cNo);
			if (c == NULL) {
				cout << "Invalid choice";
				while (c == NULL) {
					cout << "Enter valid choice of card: ";
					cin >> cNo;
					Card *c = Player2->getCardfromDeck(cNo);
				}
			}

			if (c->getcardType() == powerDown) {
				cout << "Card Played: ";
				cout << "Card Played: ";
				c->printCard();
				c->fileCard(myfile);
				Player2->reduceScore(c->getPower());
				Player1->removeCard(c);
				Player1->printPlayer();
				Player1->filePlayer(myfile);
			}

			if (c->getcardType() == powerUp) {
				cout << "Card Played: ";
				myfile << "Card Played: ";
				c->printCard();
				c->fileCard(myfile);
				Player1->increaseScore(c->getPower());
				Player1->removeCard(c);
				Player1->printPlayer();
				Player1->filePlayer(myfile);
			}

			if (c->getcardType() == steal) {
				cout << "Card Played: ";
				myfile << "Card Played: ";
				c->printCard();
				c->fileCard(myfile);
				Player1->removeCard(c);

				if (Player1->getboardIndex() == 0) {
					CardGenerator = new cardFactory(powerUp);
					c = CardGenerator->getCard();
					c->setPower(1);
					Player1->insertCard(c);
					Player2->removeCard(c);
					Player1->printPlayer();
					Player1->filePlayer(myfile);
				}
				else {
					cNo = rand() % Player2->getboardIndex();
					Card *c = Player2->getCardfromDeck(cNo);
					if (c == NULL) {
						CardGenerator = new cardFactory(powerUp);
						c = CardGenerator->getCard();
						c->setPower(1);
						Player1->insertCard(c);
						Player2->removeCard(c);
						Player1->printPlayer();
						Player1->filePlayer(myfile);
					}
					else {
						Player1->insertCard(c);
						Player2->removeCard(c);
						Player1->printPlayer();
						Player1->filePlayer(myfile);
					}
				}
			}
			turn = 1;
			cout << "\n****************************************************************************** \n\n";
			myfile << "\n****************************************************************************** \n\n";
		}

	}

	myfile.close();

	cout << "GameLog has been written to GameLog.txt\n";

	system("pause");
	return 0;
}