/*201802487 ��ǻ�Ͱ��к� ������*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Standard.h"

double Standard::calculate()const {
	int RoomCost;		//�ش� Room�� �߻��� �ݾ�.

	//���ıݾ�, Standard���� ���� ���� ���񽺰� ���� ������ �ٷ� ������ش�.
	int breakfastCost = breakfastFee * breakfastNo;

	//2�α����� fee�� �����̹Ƿ�, 2�� �ʰ����� �ƴ����� ���� ����� �޶�����.
	if (people_num <= 2) {					//���� 2�� ���϶��,
		RoomCost = breakfastCost + fee;		//ȣ�ڻ��ݾ� = ���ĺ�� + �����
	}
	else {									//2�� �ʰ����,
		RoomCost = breakfastCost + fee + (people_num - 2) * addFeePerPerson;
		//ȣ�ڻ��ݾ� = ���ıݾ� + ����� + (��ü �ο����� 2���� �� �ο�)*1�� �߰� ����
	}
	return RoomCost;	//ȣ�ڻ��ݾ� ��ȯ
}