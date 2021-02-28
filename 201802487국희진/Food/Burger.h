/*201802487 컴퓨터공학부 국희진*/

#ifndef BURGER_H
#define BURGER_H
#include "Food.h"



/*Food 클래스를 상속받는 Burger*/
class Burger :public Food {
	bool no_tomato;
public:
	Burger(string name, double price, double size_diff) :Food(name, price, size_diff) {
		no_tomato = false;			//디폴트값
	}
	virtual void option()override;
	virtual void print_option()override;
};

#endif