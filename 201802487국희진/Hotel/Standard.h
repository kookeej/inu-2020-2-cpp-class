/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef STANDARD_H
#define STANDARD_H

#include "Room.h"

/*Room�� ��ӹ޴� �Ļ�Ŭ���� Standard*/
class Standard :public Room {
public:
	Standard(int rn) :Room(rn) {
		fee = 100;					//������ 100�޷�
		addFeePerPerson = 30;		//�߰� �ο� �ݾ��� 1�δ� 30�޷� 
	}

	//calculate()�������ش�.
	virtual double calculate()const override;
};

#endif
