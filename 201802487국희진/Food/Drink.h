/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef DRINK_H
#define DRINK_H
#include "Food.h"



/*Food Ŭ������ ��ӹ޴� Drink*/
class Drink : public Food {
	bool no_ice;
public:
	Drink(string name, double price, double size_diff) :Food(name, price, size_diff) {
		no_ice = false;				//����Ʈ��
	}
	virtual void option()override;
	virtual void print_option()override;
};

#endif