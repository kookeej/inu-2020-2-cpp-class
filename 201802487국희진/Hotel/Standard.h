/*201802487 컴퓨터공학부 국희진*/

#ifndef STANDARD_H
#define STANDARD_H

#include "Room.h"

/*Room을 상속받는 파생클래스 Standard*/
class Standard :public Room {
public:
	Standard(int rn) :Room(rn) {
		fee = 100;					//입장료는 100달러
		addFeePerPerson = 30;		//추가 인원 금액은 1인당 30달러 
	}

	//calculate()구현해준다.
	virtual double calculate()const override;
};

#endif
