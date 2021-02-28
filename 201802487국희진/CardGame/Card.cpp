/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
using namespace std;

#include "Card.h"

Card::Card() {
	//�⺻������ Card()�� ī�带 �ʱ�ȭ �ϴ� ������ �Ѵ�.
	color = 'x';
	number = 0;
}

Card::Card(int n) {
	//Card(int n)�� ������ ī�忡 ���ڿ� ������ �����ϴ� ������ �Ѵ�.
	this->number = n;
	if (n % 2 == 0) {		//���� n�� ¦�����,
		this->color = 'b';		//'b'����(������)
	}
	else this->color = 'w';		//n�� Ȧ�����, 'w'����(���)
}

//front(): ī���� �ո�, �� ���ڸ� ��ȯ�ϴ� �Լ�
int Card::front()const {
	return this->number;
}


//back(): ī���� �޸�, �� ������ ��ȯ�ϴ� �Լ�
char Card::back()const {
	return this->color;
}