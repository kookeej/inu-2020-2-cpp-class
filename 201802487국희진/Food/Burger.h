/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef BURGER_H
#define BURGER_H
#include "Food.h"



/*Food Ŭ������ ��ӹ޴� Burger*/
class Burger :public Food {
	bool no_tomato;
public:
	Burger(string name, double price, double size_diff) :Food(name, price, size_diff) {
		no_tomato = false;			//����Ʈ��
	}
	virtual void option()override;
	virtual void print_option()override;
};

#endif