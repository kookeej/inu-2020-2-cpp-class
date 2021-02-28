/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Product.h"


/*���ο� ��ǰ�� �߰��ϱ� ���� ������ �����ε�*/
istream& operator>>(istream& ins, Product& p) {
	cout << endl;
	cout << "��ǰ �̸� �Է�: ";
	getline(ins, p.name);
	if (p.name == "no") {		//���� "no"�� �Է��� �Ǿ��ٸ� ��ǰ �߰� ����.
		cout << "���ο� ��ǰ �߰� ����" << endl << endl;
		return ins;
	}
	cout << "��ǰ ���� �Է�: ";
	ins >> p.price;
	return ins;
}



/*��ǰ�� ����ϱ� ���� ������ �����ε�, ��ǰ ��ü ���, ��ٱ��� ���, �˻��� ��ǰ ��� �� �پ��ϰ� ����*/
ostream& operator<<(ostream& stream, const Product& p) {
	stream << " ��ǰ�� : " << setw(20) << setfill(' ') << left << p.name;
	stream << " ���� : " << setw(10) << setfill(' ') << right << p.price << "�� ";
	stream << " ���/���� : " << p.stock << "�� " << endl;
	return stream;
}
