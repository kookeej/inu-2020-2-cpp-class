/*201802487 컴퓨터공학부 국희진*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

class Player {
	Card* deck;
	int num_card;		//남아있는 카드의 수
	int history[9];		//user와 computer가 선택한 카드 숫자의 기록
public:
	Player();
	void randomShuffle();
	Card choose(const int& index);
	int search(const int& number);
	void printFront()const;			//숫자 프린트
	void printBack()const;			//색깔 프린트
	void printHistory()const;		//기록 프린트
	~Player() { delete deck; };		//소멸자
};

#endif