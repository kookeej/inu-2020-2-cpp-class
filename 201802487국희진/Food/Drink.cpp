/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Drink.h"



/*Drink�� �ɼ� ����(������ ���� ���� ������)*/
void Drink::option() {
	char ch;

	/*���� �Է� ����ó��*/
	while (true) {
		cout << setw(44) << right << "+ Do you want drink no ice?(y or n) ";
		cin >> ch;
		//���� �ƴ� ���� �ԷµǾ��ų� 'y'�� 'n' �̿��� ���� �ԷµǸ� �ٽ� �Է�
		if (!cin || (ch != 'y' && ch != 'n')) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	if (ch == 'y') {		//���� �� ����
		no_ice = true;
	}
	else if (ch == 'n') {	//���� ����
		no_ice = false;
	}
}




/*Drink �ɼ�(���� ���� ����)�� ���*/
void Drink::print_option() {
	if (no_ice == true) {
		cout << setw(13) << right << "+No Ice" << endl;
	}
}