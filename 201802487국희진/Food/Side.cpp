/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Side.h"



/*Side�� �ɼ� ����(�ɫ� �ҽ� or �ӽ�Ÿ�� �ҽ�)*/
void Side::option() {
	char ch;

	/*���� �Է� ����ó��*/
	while (true) {
		cout << setw(39) << right << "+ Is ketchup sauce ok?(y or n) ";	//��ø �ҽ��� ������ ������
		cin >> ch;
		//���� �Էµ� ���ڰ� char�� �ƴϰų�, y�� n�� �ƴ϶�� �ٽ� �Է�
		if (!cin || (ch != 'y' && ch != 'n')) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	if (ch == 'y') {			//��ø �ҽ��� ����
		mustard = false;
	}
	else if (ch == 'n') {		//�ӽ�Ÿ�� �ҽ��� ����
		mustard = true;
	}
}




/*Side�ɼ�(�ҽ�)�� ���*/
void Side::print_option() {
	if (mustard == true) {		//�ӽ�Ÿ�� ����
		cout << setw(20) << right << "+mustard sauce" << endl;
	}
	else {						//�ɫ� ����
		cout << setw(20) << right << "+ketchup sauce" << endl;
	}
}