/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"

class Hotel {
	Room** rooms;
	int time;
	int size;
	int totalIncome = 0;
	RoomType* roomTypes;
	int room_to_i(const int rn);	//rn:�� �ѹ�, ��ѹ��� �Է¹޾� �ش� ��ѹ��� ���� index�� ��ȯ���ִ� �Լ�
public:
	Hotel(ifstream& setting);
	~Hotel(){}
	void open(ifstream& fin);
};

#endif