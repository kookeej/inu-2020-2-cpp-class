/*201802487 컴퓨터공학부 국희진*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Suite.h"

double Suite::calculate()const {
	int RoomCost;				//해당 Room에 발생한 금액을 더해주는 변수
	int breakfastCost;			//조식 금액

	//조식 2인까지는 무료이기 때문에 조식 인원이 2인 초과인지 아닌지에 따라 계산이 달라짐.
	if (breakfastNo >= 2) {			//조식 인원이 2인 이상일 때,
		breakfastCost = (breakfastNo - 2) * breakfastFee;		//조식 인원에서 2를 빼준다.
	}
	else {							//조식 인원이 1인 이하일 경우,
		breakfastCost = 0;			//발생하는 조식 비용 없음
	}

	//2인까지는 fee에 포함이므로, 2인 초과인지 아닌지에 따라 계산이 달라진다. Standard와 동일
	if (people_num <= 2) {
		RoomCost = breakfastCost + fee;
	}
	else {
		RoomCost = breakfastCost + fee + (people_num - 2) * addFeePerPerson;
	}

	return RoomCost;
}