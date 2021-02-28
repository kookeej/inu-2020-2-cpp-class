/*201802487 컴퓨터공학부 국희진*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Room.h"

//사용자 정의 연산자. log<<Room 수행
ofstream& operator<<(ofstream& log, const Room& r) {

	if (r.getState() == State::EMPTY) {
		log << to_string(r.getRoomNum()) << " Empty";
	}
	else if (r.getState() == State::OCCUPIED) {
		log << to_string(r.getRoomNum()) << " Occupied";
		if (r.people_num == 1) {							//만약 해당 방 총 인원이 1명이라면
			log << "(" << r.getName() << ")";				//이름만 출력
		}
		else {												//1명을 넘으면 그 외 인원까지 출력										
			log << "(" << r.getName() << " and " << r.people_num - 1 << " others) ";
		}

	}
	else if (r.getState() == State::PREPARING) {
		//Preparing상태일 경우, remainTime까지 출력. 
		log << to_string(r.getRoomNum()) << " Preparing(" << r.remainTime << " hours left)";
	}

	return log;
}



/*Room으로 체크인할 때 호출할 함수
이름, 입장할 총 인원, 조식을 먹을 인원을 입력받고 해당 객체에 저장해준다. */
void Room::checkin(string name, int people_num, int breakfastNo) {
	this->name = name;
	this->people_num = people_num;
	this->breakfastNo = breakfastNo;
}




//체크아웃을 할 때 호출할 함수
void Room::checkout() {
	state = State::PREPARING;		//상태는 Preparing으로 바뀐다.
	name = "";
	remainTime = 4;					//remainTime=4로 설정.
	people_num = 0;					//나머지 초기화
	serviceCost = 0;
}




//Room의 상태가 State::PREPARING일 때 수행할 함수
void Room::prepare() {
	remainTime -= 1;
	if (remainTime == 0) {
		state = State::EMPTY;		//remainTime==0이면 Empty로 바꿔준다.
	}
}




