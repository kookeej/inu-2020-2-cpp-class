/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef CARD_H
#define CARD_H

class Card {
	char color;		//ī���� ����(��/��) ����
	int number;		//ī���� ����(0~8) ����
public:
	Card();
	Card(int n);
	int front()const;		//���� getNumber()�� ����
	char back()const;		//�� getColor()�� ����
};

#endif