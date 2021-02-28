/*201802487 컴퓨터공학부 국희진*/

#ifndef DRINK_H
#define DRINK_H
#include "Food.h"



/*Food 클래스를 상속받는 Drink*/
class Drink : public Food {
	bool no_ice;
public:
	Drink(string name, double price, double size_diff) :Food(name, price, size_diff) {
		no_ice = false;				//디폴트값
	}
	virtual void option()override;
	virtual void print_option()override;
};

#endif