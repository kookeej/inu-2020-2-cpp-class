/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "ShoppingManager.h"



/*file�� �ε��ؿ� �� �о�� ���� ������*/
ShoppingManager::ShoppingManager(const string filename) {
	ifstream product;
	product.open(filename);			//file�� �ε��ؿ�.
	string r_name;					//�о�� �̸�
	string rs_price;				//�о�� ����(string����)
	int r_price;					//���� �������� ��ȯ�� �о�� ����
	while (product) {							//������ �о���� ����
		if (product.eof())break;				//���� ������ ���̶��, while�� Ż��
		getline(product, r_name, ';');			//';'������ �д´�.
		getline(product, rs_price, '\n');		//'\n'������ �д´�.
		r_price = stoi(rs_price);				//������ ��ȯ
		//cout << "----name: " << r_name << "---price: " << r_price << endl;	//������
		Product p(r_name, r_price);				//��ü ����
		productList.push_back(p);				//productList�� ��ü�� �־��ش�.
	}
	product.close();
}



/*���� �޴��� ���*/
void ShoppingManager::mainMenu() {
	int input;			//�Է��ϴ� ��ư
	cout << " << INU ���ο� ���� ���� ȯ���մϴ�! >>" << endl;
	cout << "[1] ���� ������ ���" << endl
		<< "[2] �� ���" << endl
		<< "[3] ����" << endl;
	while (true) {
		cout << "�Է�: ";
		cin >> input;
		if (input < 1 || input >3) {				//���� ��ư ������ ����� ����ó��
			cout << "�ٽ� �Է��Ͻÿ�. " << endl;
			continue;
		}
		else break;
	}
	switch (input)
	{
	case(1): {				//input==1�� ���
		cout << endl;
		managerMode();		//������ ��� ����
		break;
	}
	case(2): {				//input==2�� ���
		cout << endl;
		customerMode();		//�� ��� ����
		break;
	}
	case(3): {				//input==3�� ���, ���α׷� ����
		cout << "���α׷��� �����մϴ�.";
		break;
	}
	}
}



/*������ ���*/
void ShoppingManager::managerMode() {
	int pw = 1234;				//������ ��й�ȣ�� 1234
	int input_pw;				//�Է��ϴ� ��й�ȣ
	int input;					//�Է��ϴ� ��ư ��ȣ
	while (true) {
		cout << "������ ��й�ȣ�� �Է��ϼ���.(���� ȭ������ ���ư����� -1�Է�) : ";
		cin >> input_pw;
		if (input_pw == -1) {			//-1�� ��й�ȣ�� �Է��� ��� ���� ȭ������ ���ư�.
			cout << "���� ȭ������ ���ư��ϴ�." << endl << endl;
			mainMenu();
			break;
		}
		else if (input_pw == pw) {		//��й�ȣ�� ��ġ�� ���
			break;
		}
		else if (input_pw != pw) {		//��й�ȣ�� ��ġ���� ���� ���
			cout << "��й�ȣ�� Ʋ���ϴ�!" << endl;
		}
	}
	cout << endl;

	/*���⼭���� ��й�ȣ�� ��ġ�ϴ� ��츸 ����*/
	if(input_pw == pw) {
		while (true) {
			cout << "< ���� ������ ��� >" << endl;
			cout << "[1] ��ǰ �߰�" << endl
				<< "[2] ��ǰ ����" << endl
				<< "[3] ��� ��ǰ ���" << endl
				<< "[4] ���ư���" << endl;

			while (true) {
				cout << "�Է�: ";
				cin >> input;
				if (input < 1 || input > 4) {				//������ ���� ����� ����ó��
					cout << "�ٽ� �Է��Ͻÿ�. " << endl;
					continue;
				}
				else break;
			}

			switch (input)
			{
			case(1): {					//input==1�� ���
				cout << endl;
				addProduct();			//��ǰ �߰�
				break;
			}
			case(2): {					//input==2�� ���
				cout << endl;
				deleteProduct();		//��ǰ ����
				break;
			}
			case(3): {					//input==3�� ���
				cout << endl;
				print(productList);		//productList ��ü ���
				break;
			}
			case(4): {					//input==4�� ���
				break;
			}
			}

			if (input == 4) {
				cout << endl;
				mainMenu();
				break;
			}
		}
	}
}


/*��ǰ�� �߰��ϴ� �Լ�*/
void ShoppingManager::addProduct() {
	string add_name = "NULL";			//�ӽ� �ʱ�ȭ �̸� ��
	int add_price = 0;					//�ӽ� �ʱ�ȭ ����
	Product p(add_name, add_price);		//��ü ����, stock�� �Էµ��� ���� ��� default ���� 100 ����
	cout << "���ο� ��ǰ�� �߰��մϴ�. ��ǰ �Է� �� no�� �Է��ϸ� ���������ϴ�. " << endl;

	while (true) {
		bool isExist = false;		//�����ϴ� ��ǰ���� �ƴ����� �����ϴ� bool
		cin.ignore();
		cin >> p;					//������ �����ε� ����

		if (p.getName() == "no") break;						//getName()�� no�� ��� ��ǰ �߰� ����

		for (int i = 0; i < productList.size(); i++) {
			if (p.getName() == productList[i].getName()) {
				isExist = true;								//�̹� productList�� �����ϸ� isExist==true�� ����
				break;
			}
		}

		if (isExist == true) {								//�̹� �����Ѵٸ�
			cout << "�̹� �����ϴ� ��ǰ�Դϴ�." << endl;
			continue;
		}
		else {												//�����ϴ� ��ǰ�� �ƴ϶��
			cout << p.getName() << " ��(��) ��Ͽ� ����߽��ϴ�." << endl;
			productList.push_back(p);
		}
	}
}



/*��ǰ ���� �Լ�*/
void ShoppingManager::deleteProduct() {
	string del_name;						//������ ��ǰ �̸�	
	bool isExist = false;					//��ǰ�� �����ϴ��� �ƴ����� Ȯ���� bool
	vector<Product>::iterator it;			//erase()�� ����ϱ� ���� iterator ����
	cout << "�����Ͻ� ��ǰ�� �̸��� �Է��ϼ���: ";
	cin >> del_name;

	for (it = productList.begin(); it != productList.end(); it++) {
		if (del_name == (*it).getName()) {			//���� ������ ��ǰ�� �����Ѵٸ�
			isExist = true;							//isExist==true�� ����
			productList.erase(it);					//�ش� ��ǰ ����
			break;
		}
	}

	if (isExist == false) {							//���� ��ǰ�� ���ٸ�
		cout << "�Է��Ͻ� ��ǰ�� ��Ͽ� �����ϴ�. " << endl << endl;
	}

	else {											//��ǰ�� �����ϹǷ�
		cout << del_name << " ��(��) �����մϴ�." << endl << endl;
	}
}



/*��ǰ ����� ����ϴ� �Լ�*/
void ShoppingManager::print(vector<Product> pList) {
	for (int i = 0; i < pList.size(); i++) {
		cout << pList[i];
	}
	cout << endl << "�� " << pList.size() << "������ ��ǰ" << endl << endl;
}



/*�� ���*/
void ShoppingManager::customerMode() {

	while (true) {
		int input;							//�Է��� ��ư ��ȣ
		cout << "< �� ��� >" << endl;
		cout << "[1] ��ǰ ����" << endl
			<< "[2] ��ǰ �˻�" << endl
			<< "[3] ��ٱ��� ���" << endl
			<< "[4] ���ư���" << endl;

		while (true) {
			cout << "�Է�: ";
			cin >> input;
			if (input < 1 || input >4) {
				cout << "�ٽ� �Է��Ͻÿ�. " << endl;
				continue;
			}
			else break;

		}


		switch (input)
		{
		case(1): {					//input==1�̶��
			cout << endl;
			print(productList);		//productList���
			break;
		}
		case(2): {					//input==2�̶��
			cout << endl;
			search();				//��ǰ ã��
			break;
		}
		case(3): {					//input==3�̶��
			cout << endl;
			cartMode();				//��ٱ��� ���
			break;
		}
		case(4): {					//input==4��� ���ư��� ����
			cout << endl;	
			break;
		}
		}

		//case(3)�� ������ �� ������ �ڵ�
		if (input == 3) {		
			customerMode();
			break;
		}
		
		if (input == 4) {		//���ѷ��� ���������� �ڵ�
			mainMenu();
			break;
		}
	}
}



/*��ǰ�� ã�� �Լ�*/
void ShoppingManager::search() {
	string search_name;				//ã������ ��ǰ �̸�
	char ch;						//getline�� �������� �ذ��ϱ� ���� ���� ����
	int index = -1;					//index�� �ʱⰪ�� -1�� �����Ѵ�.

	cout << "��ǰ���� �Է��ϼ���: ";

	ch = cin.peek();				//���� ������.
	if (ch == '\n') {				//���� ch=='\n'���
		cin.ignore(1, '\n');		//ignore�� ���۸� ����.
	}

	getline(cin, search_name);
	for (int i = 0; i < productList.size(); i++) {
		if (search_name == productList[i].getName()) {			//�����Ѵٸ�
			index = i;											//�ش� �ε������� ����
			cout << productList[index];							//�ش� �ε��� ��ü ���
			cout << endl;
			break;
		}
	}
	//���� index�� -1���� �״�ζ�� ã�� ��ǰ�� ���ٴ� �ǹ�.
	if (index == -1) {
		cout << "�Է��Ͻ� ��ǰ�� ���� ��ϵǾ� ���� �ʽ��ϴ�." << endl << endl;
	}
}



/*��ٱ��� ���*/
void ShoppingManager::cartMode() {
	vector<Product> cart;			//cart vector ����
	while (true) {
		int input;					//�Է��Ϸ��� ��ư ��ȣ

		cout << "< ��ٱ��� ��� >" << endl;
		cout << "[1] ��ǰ ����" << endl
			<< "[2] ��ٱ��Ͽ� ���" << endl
			<< "[3] ��ٱ��� ���" << endl
			<< "[4] ����ϱ�" << endl;

		while (true) {
			cout << "�Է�: ";
			cin >> input;
			if (input < 1 || input >4) {			//������ �Ѿ ��� ���� ó��
				cout << "�ٽ� �Է��Ͻÿ�. " << endl;
				continue;
			}
			else break;
		}

		switch (input)
		{
		case(1): {						//input==1�� ���
			cout << endl;
			print(productList);			//��ü ��ǰ ���
			break;
		}
		case(2): {						//input==2�� ���
			cout << endl;
			cart = addToCart(cart);		//��ٱ��Ͽ� ��� addToCart(cart)�� ��ȯ���� �ٽ� cart�� ����
			break;
		}
		case(3): {						//input==3�� ���
			cout << endl;
			print(cart);				//��ٱ��� ���
			break;
		}
		case(4): {						//input==4�� ���
			cout << endl;
			calculate(cart);			//��ٱ��Ͽ� ��� ��ǰ�� ���
			cout << "��ٱ��� ��带 �����մϴ�." << endl;
			break;
		}

		}
		//case(4)�� ��� ������ �� ������ �ڵ�
		if (input == 4) {				//input==4�� ��� ��ٱ��ϸ�� �����
			cout << endl;
			break;
		}
	}

}
	



/*��ٱ��Ͽ� ���*/
vector<Product> ShoppingManager::addToCart(vector<Product> pCart) {
	string want_name;				//���ϴ� ��ǰ �̸�
	int want_stock;					//���ϴ� ���
	int rest_stock;					//���� ���
	char ch;						//Ȯ�� ����
	vector<Product>::iterator it;

	while (want_name != "no") {			//"no"�� �Էµ� ������ �ݺ�
		bool isExist = false;			//��ǰ�� �����ϴ��� �ƴ����� Ȯ���� �� �ִ� bool

		cout << "�����ϰ��� �ϴ� ��ǰ �̸� �Է�(��ٱ��� ��� ����� no �Է�): ";

		//getline�� �������� �ذ��ϱ� ���� �ڵ�
		ch = cin.peek();
		if (ch == '\n') {
			cin.ignore(1, '\n');
		}

		getline(cin, want_name);
		//cout << "----want_name: " << want_name << "-------" << endl;	//������

		for (it = productList.begin(); it != productList.end(); it++) {
			if (want_name == (*it).getName()) {				//��ǰ�� �����Ѵٸ� ��ٱ��Ͽ� ���
				isExist = true;
				cout << "���� ���� �Է�(" << want_name << "�� ���� ���: " << (*it).getStock() << "): ";

				cin >> want_stock;
				if (want_stock <= (*it).getStock()) {		//���ϴ� ��� ���� ����� ���ų� ���ٸ� ��ٱ��Ͽ� ���
					cout << want_name << " " << want_stock << "���� ��ٱ��Ͽ� ��ҽ��ϴ�." << endl << endl;

					rest_stock = (*it).getStock() - want_stock;		//���� ��� ���
					(*it).setStock(rest_stock);						//���� ��� ���Ӱ� ����

					Product pcart(want_name, (*it).getPrice(), want_stock);		//pcart��ü ����
					int tmp_index = -1;

					//��ٱ��Ͽ� ���� ��ǰ�� �ִٸ� ���� ��ü�� pCart�� �߰����� �ʰ� ���� ��ü�� ��� want_stock�� ���Ѵ�.
					for (int i = 0; i < pCart.size(); i++) {
						if (pcart.getName() == pCart[i].getName()) {			//�̹� ��ٱ��Ͽ� ���� ��ǰ�̶��
							tmp_index = i;
							int new_stock = pCart[i].getStock() + pcart.getStock();		//���Ӱ� ����� ��ٱ��Ͼ� ��ǰ�� ����
							pCart[tmp_index].setStock(new_stock);
							break;
						}
					}

					if (tmp_index == -1) {			//��ٱ��Ͽ� ���� ��ǰ�̶��
						pCart.push_back(pcart);		//pCart�� ���Ӱ� �߰�
					}
				}

				else {
					cout << "��� �����Ͽ� ���� �� �ش� ��ǰ�� ���� �� �����ϴ�." << endl << endl;
				}

				break;
			}
		}

		if (isExist == false) {
			cout << "�Է��Ͻ� ��ǰ�� ���� ��ϵǾ� ���� �ʽ��ϴ�." << endl << endl;
		}
	}

	return pCart;
}



/*��ٱ��Ͽ� �ִ� ��ǰ ��� �Լ�*/
int ShoppingManager::calculate(const vector<Product> pCart) {
	int total_price = 0;

	for (int i = 0; i < pCart.size(); i++) {
		total_price += (pCart[i].getPrice() * pCart[i].getStock());		//��ü ���� ���
		cout << pCart[i];
	}

	cout << endl;
	cout << "�� " << pCart.size() << "������ ��ǰ" << endl << endl;
	cout << "�� " << total_price << "�� ���� �Ϸ�Ǿ����ϴ�." << endl;
	return total_price;
}