/*201802487 ��ǻ�Ͱ��к� ������*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Royal.h"

double Royal::calculate()const {
	int breakfastCost;
	int RoomCost;

	//���� 2�� ����
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