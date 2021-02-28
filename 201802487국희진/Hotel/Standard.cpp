/*201802487 컴퓨터공학부 국희진*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Standard.h"

double Standard::calculate()const {
	int RoomCost;		//해당 Room에 발생한 금액.

	//조식금액, Standard에는 조식 무료 서비스가 없기 때문에 바로 계산해준다.
	int breakfastCost = breakfastFee * breakfastNo;

	//2인까지는 fee에 포함이므로, 2인 초과인지 아닌지에 따라 계산이 달라진다.
	if (people_num <= 2) {					//만약 2인 이하라면,
		RoomCost = breakfastCost + fee;		//호텔사용금액 = 조식비용 + 입장료
	}
	else {									//2인 초과라면,
		RoomCost = breakfastCost + fee + (people_num - 2) * addFeePerPerson;
		//호텔사용금액 = 조식금액 + 입장료 + (전체 인원에서 2인을 뺀 인원)*1인 추가 가격
	}
	return RoomCost;	//호텔사용금액 반환
}