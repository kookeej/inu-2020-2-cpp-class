/*201802487 컴퓨터공학부 국희진*/

#ifndef CARD_H
#define CARD_H

class Card {
	char color;		//카드의 색깔(흑/백) 저장
	int number;		//카드의 숫자(0~8) 저장
public:
	Card();
	Card(int n);
	int front()const;		//숫자 getNumber()의 역할
	char back()const;		//색 getColor()의 역할
};

#endif