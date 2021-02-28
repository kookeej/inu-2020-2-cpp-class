/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef CART_H
#define CART_H
#include "Player.h"

class Game {
	Player* computer;
	Player* user;
	int round;
	bool comp_first; //true �� ����, false ��������
	int user_win;
	int comp_win;
public:
	Game();
	void play();
	void advanceRound(); //9�� ȣ���ϴ� ���� play()�� �ϴ� ��
	~Game() { delete computer; delete user; }
};


#endif