/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef SIDE_H
#define SIDE_H
#include "Food.h"



/*Food Ŭ������ ��ӹ޴� Side*/
class Side :public Food {
	bool mustard;
public:
	Side(string name, double price, double size_diff) :Food(name, price, size_diff) {
		mustard = false;		 //����Ʈ��
	}
	virtual void option()override;
	virtual void print_option()override;
};

#endif