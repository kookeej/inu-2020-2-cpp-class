/*201802487 ��ǻ�Ͱ��к� ������*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Room.h"

//����� ���� ������. log<<Room ����
ofstream& operator<<(ofstream& log, const Room& r) {

	if (r.getState() == State::EMPTY) {
		log << to_string(r.getRoomNum()) << " Empty";
	}
	else if (r.getState() == State::OCCUPIED) {
		log << to_string(r.getRoomNum()) << " Occupied";
		if (r.people_num == 1) {							//���� �ش� �� �� �ο��� 1���̶��
			log << "(" << r.getName() << ")";				//�̸��� ���
		}
		else {												//1���� ������ �� �� �ο����� ���										
			log << "(" << r.getName() << " and " << r.people_num - 1 << " others) ";
		}

	}
	else if (r.getState() == State::PREPARING) {
		//Preparing������ ���, remainTime���� ���. 
		log << to_string(r.getRoomNum()) << " Preparing(" << r.remainTime << " hours left)";
	}

	return log;
}



/*Room���� üũ���� �� ȣ���� �Լ�
�̸�, ������ �� �ο�, ������ ���� �ο��� �Է¹ް� �ش� ��ü�� �������ش�. */
void Room::checkin(string name, int people_num, int breakfastNo) {
	this->name = name;
	this->people_num = people_num;
	this->breakfastNo = breakfastNo;
}




//üũ�ƿ��� �� �� ȣ���� �Լ�
void Room::checkout() {
	state = State::PREPARING;		//���´� Preparing���� �ٲ��.
	name = "";
	remainTime = 4;					//remainTime=4�� ����.
	people_num = 0;					//������ �ʱ�ȭ
	serviceCost = 0;
}




//Room�� ���°� State::PREPARING�� �� ������ �Լ�
void Room::prepare() {
	remainTime -= 1;
	if (remainTime == 0) {
		state = State::EMPTY;		//remainTime==0�̸� Empty�� �ٲ��ش�.
	}
}




