/*201802487 컴퓨터공학부 국희진*/

#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"

class Hotel {
	Room** rooms;
	int time;
	int size;
	int totalIncome = 0;
	RoomType* roomTypes;
	int room_to_i(const int rn);	//rn:룸 넘버, 룸넘버를 입력받아 해당 룸넘버를 가진 index를 반환해주는 함수
public:
	Hotel(ifstream& setting);
	~Hotel(){}
	void open(ifstream& fin);
};

#endif