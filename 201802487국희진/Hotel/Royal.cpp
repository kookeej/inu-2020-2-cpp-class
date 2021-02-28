/*201802487 컴퓨터공학부 국희진*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Royal.h"

double Royal::calculate()const {
	int breakfastCost;
	int RoomCost;

	//조식 2인 무료
	if (breakfastNo >= 2) {
		breakfastCost = (breakfastNo - 2) * breakfastFee;
	}
	else {
		breakfastCost = 0;
	}

	if (people_num <= 2) {
		RoomCost = breakfastCost + fee;
	}
	else {
		RoomCost = breakfastCost + fee + (people_num - 2) * addFeePerPerson;
	}
	return RoomCost;
}