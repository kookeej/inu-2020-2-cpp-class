/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Manager.h"



/*vector�� �޾� �޴� ����ϴ� �Լ�*/
template <class T>
void Manager::print_vector(T vec) {		//vector�� vector<Burger>, <Side>, <Drink>�� �� �� �ִ�.

	int input_name;				//���� ��ȣ �Է�
	int input_size;				//���� ������ ��ȣ �Է�
	int idx;					//idx=input_name-1�� ���༭ �ε����� ����� ��.

	//�޴��� �Է� �޴´�.
	cout << setw(6) << right << "1:" << vec[0].get_name() << endl;		//�޴� ���
	cout << setw(6) << right << "2:" << vec[1].get_name() << endl;

	/*���� �Է� ����ó��*/
	while (true) {
		cout << setw(16) << right << "Choose num: ";
		cin >> input_name;
		//���� �Էµ� ���� ������ �ƴϰų� ������ �Ѿ�� ���,
		if (!cin || (input_name < 1 || input_name > 2)) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	idx = input_name - 1;	//vector�� �ε����� ����ϱ� ����

	//����� �Է� �޴´�.
	cout << setw(26) << right << "What size do you want?" << endl;
	cout << setw(56) << right << "0: cancel order    1: small    2: medium    3: large" << endl;

	/*���� �Է� ����ó��*/
	while (true) {
		cout << setw(16) << right << "Choose num: ";
		cin >> input_size;
		//���� �Էµ� ���� ������ �ƴϰų� ������ �Ѿ�� ���,
		if (!cin || (input_size < 0 || input_size > 3)) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	if (input_size == 0) return;		//0�� �Էµƴٸ� �Լ��� ����

	/*�Ű������� �޴� vec�� Ÿ�Կ� ���� �޶�����.*/
	if (typeid(vec) == typeid(burger_list)) {		//vec�� burger_list�� Ÿ�԰� ���ٸ�,
		Burger* b = new Burger(vec[idx].get_name(), vec[idx].get_price(), vec[idx].get_size_diff());	//Burger��ü ���� ����
		b->option();					//�ɼ� ���� ���
		b->set_size(input_size);		//������ set.
		cart.push_back(b);				//��ٱ��Ͽ� ���
	}
	else if (typeid(vec) == typeid(side_list)) {	//vec�� side_list�� Ÿ�԰� ���ٸ�,
		Side* s = new Side(vec[idx].get_name(), vec[idx].get_price(), vec[idx].get_size_diff());		//Side��ü ���� ����
		s->option();					//�ɼ� ���� ���
		s->set_size(input_size);		//����� set.
		cart.push_back(s);				//��ٱ��Ͽ� ���
	}
	else if (typeid(vec) == typeid(drink_list)) {
		Drink* d = new Drink(vec[idx].get_name(), vec[idx].get_price(), vec[idx].get_size_diff());
		d->option();					//�ɼ� ���� ���
		d->set_size(input_size);		//����� set.
		cart.push_back(d);				//��ٱ��Ͽ� ���
	}

}




/*menu.txt�κ��� �޴��� �о���� �Լ�*/
void Manager::load_menu(ifstream& menu) {
	string r_name;				//�о�� �޴� �̸�
	string rs_price;			//�о�� �޴� ����
	string rs_size_diff;		//�о�� ����� ������
	double r_size_diff;			//�о�� ����� �������� double������ �����ϴ� ����
	double r_price;				//�о�� �޴� ������ double������ �����ϴ� ����
	string s;
	char ch;		//����'\0'������ ���� ����

	while (menu) {
		if (menu.eof())break;		//���� menu.txt�� ���̶�� �ݺ��� Ż��
		menu >> s;

		/*���ڿ� s�� ���� ��, ���� �������� ������, ���Ͽ��� ���� ���ڿ��� ���� ��, �� �տ� ���鹮��'\0'�� ���ԵǴ� ������
		�޴� �̸��� ��Ȯ�� ������� �ʴ� �������� �����ϱ� ���� ���*/
		menu.get(ch);				//����'\0'�� ch�� ���������ν�, ���� ��� " cheese burger"�� �ƴ� "cheese burger"�� ������ �� �ִ�.
		getline(menu, r_name, ';');
		menu >> rs_price >> rs_size_diff;

		//�Է¹޴� �޴� ����, ����� ������ ���ڿ��� double������ ��ȯ(stod���)
		r_size_diff = stod(rs_size_diff);
		r_price = stod(rs_price);

		if (s == "b") {				//Burger��ü ���� �� burger_list�� �־��ֱ�.
			Burger b(r_name, r_price, r_size_diff);
			burger_list.push_back(b);
		}
		else if (s == "s") {		//Side��ü ���� �� side_list�� �־��ֱ�.
			Side s(r_name, r_price, r_size_diff);
			side_list.push_back(s);
		}
		else if (s == "d") {		//Drink��ü ���� �� drink_list�� �־��ֱ�.
			Drink d(r_name, r_price, r_size_diff);
			drink_list.push_back(d);
		}
	}
}




/*�޴� �ֹ� ȭ�� ���*/
void Manager::order() {
	int input;
	cout << "Welcome to my Burger shop!!!" << endl;
	while (true) {
		cout << "Choose the menu you want to see." << endl;
		cout << "0 : to payment" << endl;
		cout << "1 : burgers" << endl;
		cout << "2 : sides" << endl;
		cout << "3 : drinks" << endl;

		/*���� �Է� ����ó��*/
		while (true) {
			cout << "Choose num: ";
			cin >> input;
			//���� ������ �ƴϰų� ������ �Ѿ�� ������ �Էµȴٸ� �ٽ� �Է�
			if (!cin || (input < 0 || input > 3)) {
				cin.clear();
				cin.ignore();
			}
			else break;
		}


		switch (input)
		{
		case 0: {
			if (cart.empty()) {			//cart�� ����ִٸ�, ��ٱ��Ͽ� ��ǰ�� ���ٰ� ���
				cout << "No item is in the cart!";
			}
			break;
		}
		case 1: {
			cout << "  --Burger Menu--" << endl;
			print_vector(burger_list);
			break;
		}
		case 2: {
			cout << "  --Side Menu--" << endl;
			print_vector(side_list);
			break;
		}
		case 3: {
			cout << "  --Drink Menu--" << endl;
			print_vector(drink_list);
			break;
		}
		}
		if (input == 0)break;	//while�� Ż��
	}
}




/*���� ���� ������ �Լ�
cart�� ��ǰ���� �������̵��� �����ڸ� �̿��ؼ� ����ϴ� �Լ�*/
void Manager::my_print(vector<Food*>& pcart)const {
	for (int i = 0; i < pcart.size(); i++) {
		cout << *pcart[i];				//pcart���
		pcart[i]->print_option();		//���õ� �ɼǻ��׵� ���
	}
}




/*�������� ����ϴ� �Լ�*/
void Manager::receipt() {
	double total_price = 0;
	cout << endl;

	if (!cart.empty()) {		//���� ��ٱ��ϰ� ������� �ʴٸ� ������ ���.
		for (int i = 0; i < cart.size(); i++) {
			total_price += cart[i]->get_price();		//��ٱ����� ��ǰ���� ���� ��� ���ϱ�
		}

		cout << setw(25) << setfill(' ') << right << "==Order list==" << endl << endl;
		cout << setw(18) << setfill(' ') << right << "description";
		cout << setw(15) << setfill(' ') << right << "price";
		cout << endl << "----------------------------------------" << endl;
		my_print(cart);				//��ٱ��� ���
		cout << "----------------------------------------" << endl;
		cout << setw(29) << setfill(' ') << right << "Total: \\" << total_price << endl;		//�� �ݾ� ���
	}
	cout << endl;

}




/*��ٱ��ϸ� ����ִ� �Լ�*/
void Manager::clear_cart() {
	for (auto it = cart.begin(); it != cart.end();) {
		it = cart.erase(it);
	}
}