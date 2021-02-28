/*201802487 컴퓨터공학부 국희진*/

#ifndef  SUITE_H
#define SUITE_H

#include "Room.h"

class Suite : public Room {
public:
	Suite(int rn) :Room(rn) {
		fee = 300;					//Suite의 입장료는 300달러
		addFeePerPerson = 40;		//추가 인원 가격은 1인당 40달러
	}
	virtual double calculate()const override;
};

#endif
