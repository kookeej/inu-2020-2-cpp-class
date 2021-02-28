/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
using namespace std;

#include "Card.h"

Card::Card() {
	//기본생성자 Card()는 카드를 초기화 하는 역할을 한다.
	color = 'x';
	number = 0;
}

Card::Card(int n) {
	//Card(int n)은 생성한 카드에 숫자와 색깔을 저장하는 역할을 한다.
	this->number = n;
	if (n % 2 == 0) {		//만약 n이 짝수라면,
		this->color = 'b';		//'b'저장(검은색)
	}
	else this->color = 'w';		//n이 홀수라면, 'w'저장(흰색)
}

//front(): 카드의 앞면, 즉 숫자를 반환하는 함수
int Card::front()const {
	return this->number;
}


//back(): 카드의 뒷면, 즉 색깔을 반환하는 함수
char Card::back()const {
	return this->color;
}