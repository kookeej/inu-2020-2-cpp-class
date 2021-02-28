/*201802487 컴퓨터공학부 국희진*/

#ifndef SIDE_H
#define SIDE_H
#include "Food.h"



/*Food 클래스를 상속받는 Side*/
class Side :public Food {
	bool mustard;
public:
	Side(string name, double price, double size_diff) :Food(name, price, size_diff) {
		mustard = false;		 //디폴트값
	}
	virtual void option()override;
	virtual void print_option()override;
};

#endif