/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef  SUITE_H
#define SUITE_H

#include "Room.h"

class Suite : public Room {
public:
	Suite(int rn) :Room(rn) {
		fee = 300;					//Suite�� ������ 300�޷�
		addFeePerPerson = 40;		//�߰� �ο� ������ 1�δ� 40�޷�
	}
	virtual double calculate()const override;
};

#endif
