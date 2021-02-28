/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Side.h"



/*Side의 옵션 선택(케쳡 소스 or 머스타드 소스)*/
void Side::option() {
	char ch;

	/*문자 입력 예외처리*/
	while (true) {
		cout << setw(39) << right << "+ Is ketchup sauce ok?(y or n) ";	//케첩 소스를 선택할 것인지
		cin >> ch;
		//만약 입력된 문자가 char가 아니거나, y나 n가 아니라면 다시 입력
		if (!cin || (ch != 'y' && ch != 'n')) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	if (ch == 'y') {			//케첩 소스를 선택
		mustard = false;
	}
	else if (ch == 'n') {		//머스타드 소스를 선택
		mustard = true;
	}
}




/*Side옵션(소스)를 출력*/
void Side::print_option() {
	if (mustard == true) {		//머스타드 선택
		cout << setw(20) << right << "+mustard sauce" << endl;
	}
	else {						//케쳡 선택
		cout << setw(20) << right << "+ketchup sauce" << endl;
	}
}