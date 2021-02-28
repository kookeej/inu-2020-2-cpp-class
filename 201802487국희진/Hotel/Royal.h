/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef ROYAL_H
#define ROYAL_H

#include "Room.h"


class Royal :public Room {
public:
	Royal(int rn) :Room(rn) {
		fee = 500;					//Royal ������ 500�޷�
		addFeePerPerson = 50;		//�߰� �ο� ������ 1�δ� 50�޷�
	}
	virtual double calculate()const override;

	/*Room Service��� ���*/
	virtual void roomService(int rs) override {			//rs�� Room Service ���
		serviceCost += rs;		//ȣ�� ��� �ݾ׿� �Է¹��� Room Service����� �����ش�.
	}

};

#endif
