/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Burger.h"



/*Burger�� �ɼ� ����(�丶�並 ������ ������)*/
void Burger::option() {
	char ch;

	/*���� �Է� ����ó��*/
	while (true) {
		cout << setw(45) << right << "+ Will you exclude tomato ? (y or n) ";
		cin >> ch;
		//���� �Էµ� ���ڰ� char�� �ƴϰų�, y�� n�� �ƴ϶�� �ٽ� �Է�
		if (!cin || (ch != 'y' && ch != 'n')) {
			cin.clear();
			cin.ignore();		//���۸� ����ش�.
		}
		else break;		//y �Ǵ� n�� �Էµƴٸ� �ݺ��� Ż��
	}

	if (ch == 'y') {		//'y'��� �丶�� ����
		no_tomato = true;
	}
	else if (ch == 'n') {	//'n'��� �丶�� ������
		no_tomato = false;
	}
}




/*Burger�ɼ�(Tomatoes)�� ���*/
void Burger::print_option() {
	if (no_tomato == true) {
		cout << setw(27) << right << "Tomatoes are excluded" << endl;
	}
}