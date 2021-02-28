/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Drink.h"



/*Drink의 옵션 선택(얼음을 넣지 않을 것인지)*/
void Drink::option() {
	char ch;

	/*문자 입력 예외처리*/
	while (true) {
		cout << setw(44) << right << "+ Do you want drink no ice?(y or n) ";
		cin >> ch;
		//문자 아닌 값이 입력되었거나 'y'나 'n' 이외의 값이 입력되면 다시 입력
		if (!cin || (ch != 'y' && ch != 'n')) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	if (ch == 'y') {		//얼음 안 넣음
		no_ice = true;
	}
	else if (ch == 'n') {	//얼음 넣음
		no_ice = false;
	}
}




/*Drink 옵셕(얼음 포함 여부)을 출력*/
void Drink::print_option() {
	if (no_ice == true) {
		cout << setw(13) << right << "+No Ice" << endl;
	}
}