/*201802487 컴퓨터공학부 국희진*/

#ifndef ROYAL_H
#define ROYAL_H

#include "Room.h"


class Royal :public Room {
public:
	Royal(int rn) :Room(rn) {
		fee = 500;					//Royal 입장료는 500달러
		addFeePerPerson = 50;		//추가 인원 가격은 1인당 50달러
	}
	virtual double calculate()const override;

	/*Room Service비용 계산*/
	virtual void roomService(int rs) override {			//rs는 Room Service 비용
		serviceCost += rs;		//호텔 사용 금액에 입력받은 Room Service비용을 더해준다.
	}

};

#endif
