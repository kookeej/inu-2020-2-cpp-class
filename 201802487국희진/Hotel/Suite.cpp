/*201802487 ��ǻ�Ͱ��к� ������*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Suite.h"

double Suite::calculate()const {
	int RoomCost;				//�ش� Room�� �߻��� �ݾ��� �����ִ� ����
	int breakfastCost;			//���� �ݾ�

	//���� 2�α����� �����̱� ������ ���� �ο��� 2�� �ʰ����� �ƴ����� ���� ����� �޶���.
	if (breakfastNo >= 2) {			//���� �ο��� 2�� �̻��� ��,
		breakfastCost = (breakfastNo - 2) * breakfastFee;		//���� �ο����� 2�� ���ش�.
	}
	else {							//���� �ο��� 1�� ������ ���,
		breakfastCost = 0;			//�߻��ϴ� ���� ��� ����
	}

	//2�α����� fee�� �����̹Ƿ�, 2�� �ʰ����� �ƴ����� ���� ����� �޶�����. Standard�� ����
	if (people_num <= 2) {
		RoomCost = breakfastCost + fee;
	}
	else {
		RoomCost = breakfastCost + fee + (people_num - 2) * addFeePerPerson;
	}

	return RoomCost;
}