/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Food.h"



/*����� �����ϴ� �Լ�*/
void Food::set_size(const int i) {

	if (i == 1) {				//i�� 1�̶�� ������� SMALL
		size = Size::SMALL;
		base_price -= size_diff;	//�⺻ �ݾ�(base_price)���� size_diff�� ���ش�.
	}
	else if (i == 2) {
		size = Size::MEDIUM;		//�⺻ �ݾ� �״��
	}
	else if (i == 3) {
		size = Size::LARGE;
		base_price += size_diff;	//�⺻ �ݾ�(base_price)���� size_diff�� ���Ѵ�.
	}

}




/*������ �������̵�*/
ostream& operator<<(ostream& os, const Food& f) {
	//name���
	os << setw(15) << setfill(' ') << left << f.name;

	//������ ���
	if (f.size == Size::SMALL) {
		os << setw(5) << right << "S";
	}
	else if (f.size == Size::MEDIUM) {
		os << setw(5) << right << "M";
	}
	else if (f.size == Size::LARGE) {
		os << setw(5) << right << "L";
	}

	os << setw(9) << right << "\\" << f.base_price << endl;		//�ݾ� ���
	return os;
}