/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Burger.h"



/*Burger의 옵션 선택(토마토를 포함할 것인지)*/
void Burger::option() {
	char ch;

	/*문자 입력 예외처리*/
	while (true) {
		cout << setw(45) << right << "+ Will you exclude tomato ? (y or n) ";
		cin >> ch;
		//만약 입력된 문자가 char가 아니거나, y나 n가 아니라면 다시 입력
		if (!cin || (ch != 'y' && ch != 'n')) {
			cin.clear();
			cin.ignore();		//버퍼를 비워준다.
		}
		else break;		//y 또는 n가 입력됐다면 반복문 탈출
	}

	if (ch == 'y') {		//'y'라면 토마토 포함
		no_tomato = true;
	}
	else if (ch == 'n') {	//'n'라면 토마토 미포함
		no_tomato = false;
	}
}




/*Burger옵션(Tomatoes)을 출력*/
void Burger::print_option() {
	if (no_tomato == true) {
		cout << setw(27) << right << "Tomatoes are excluded" << endl;
	}
}