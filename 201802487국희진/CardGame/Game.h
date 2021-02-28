/*201802487 컴퓨터공학부 국희진*/

#ifndef CART_H
#define CART_H
#include "Player.h"

class Game {
	Player* computer;
	Player* user;
	int round;
	bool comp_first; //true 컴 먼저, false 유저먼저
	int user_win;
	int comp_win;
public:
	Game();
	void play();
	void advanceRound(); //9번 호출하는 것이 play()가 하는 일
	~Game() { delete computer; delete user; }
};


#endif