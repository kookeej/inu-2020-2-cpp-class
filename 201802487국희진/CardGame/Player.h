/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

class Player {
	Card* deck;
	int num_card;		//�����ִ� ī���� ��
	int history[9];		//user�� computer�� ������ ī�� ������ ���
public:
	Player();
	void randomShuffle();
	Card choose(const int& index);
	int search(const int& number);
	void printFront()const;			//���� ����Ʈ
	void printBack()const;			//���� ����Ʈ
	void printHistory()const;		//��� ����Ʈ
	~Player() { delete deck; };		//�Ҹ���
};

#endif