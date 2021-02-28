/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Food.h"



/*사이즈를 설정하는 함수*/
void Food::set_size(const int i) {

	if (i == 1) {				//i가 1이라면 사이즈는 SMALL
		size = Size::SMALL;
		base_price -= size_diff;	//기본 금액(base_price)에서 size_diff를 빼준다.
	}
	else if (i == 2) {
		size = Size::MEDIUM;		//기본 금액 그대로
	}
	else if (i == 3) {
		size = Size::LARGE;
		base_price += size_diff;	//기본 금액(base_price)에서 size_diff를 더한다.
	}

}




/*연산자 오버라이딩*/
ostream& operator<<(ostream& os, const Food& f) {
	//name출력
	os << setw(15) << setfill(' ') << left << f.name;

	//사이즈 출력
	if (f.size == Size::SMALL) {
		os << setw(5) << right << "S";
	}
	else if (f.size == Size::MEDIUM) {
		os << setw(5) << right << "M";
	}
	else if (f.size == Size::LARGE) {
		os << setw(5) << right << "L";
	}

	os << setw(9) << right << "\\" << f.base_price << endl;		//금액 출력
	return os;
}