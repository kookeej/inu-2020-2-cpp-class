/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Manager.h"



/*vector를 받아 메뉴 출력하는 함수*/
template <class T>
void Manager::print_vector(T vec) {		//vector는 vector<Burger>, <Side>, <Drink>가 될 수 있다.

	int input_name;				//음식 번호 입력
	int input_size;				//음식 사이즈 번호 입력
	int idx;					//idx=input_name-1을 해줘서 인덱스로 사용할 것.

	//메뉴를 입력 받는다.
	cout << setw(6) << right << "1:" << vec[0].get_name() << endl;		//메뉴 출력
	cout << setw(6) << right << "2:" << vec[1].get_name() << endl;

	/*정수 입력 예외처리*/
	while (true) {
		cout << setw(16) << right << "Choose num: ";
		cin >> input_name;
		//만약 입력된 값이 정수가 아니거나 범위를 넘어갔을 경우,
		if (!cin || (input_name < 1 || input_name > 2)) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	idx = input_name - 1;	//vector의 인덱스로 사용하기 위해

	//사이즈를 입력 받는다.
	cout << setw(26) << right << "What size do you want?" << endl;
	cout << setw(56) << right << "0: cancel order    1: small    2: medium    3: large" << endl;

	/*정수 입력 예외처리*/
	while (true) {
		cout << setw(16) << right << "Choose num: ";
		cin >> input_size;
		//만약 입력된 값이 정수가 아니거나 범위를 넘어갔을 경우,
		if (!cin || (input_size < 0 || input_size > 3)) {
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	if (input_size == 0) return;		//0이 입력됐다면 함수를 종료

	/*매개변수로 받는 vec의 타입에 따라 달라진다.*/
	if (typeid(vec) == typeid(burger_list)) {		//vec이 burger_list의 타입과 같다면,
		Burger* b = new Burger(vec[idx].get_name(), vec[idx].get_price(), vec[idx].get_size_diff());	//Burger객체 동적 생성
		b->option();					//옵션 선택 출력
		b->set_size(input_size);		//사이즈 set.
		cart.push_back(b);				//장바구니에 담기
	}
	else if (typeid(vec) == typeid(side_list)) {	//vec이 side_list의 타입과 같다면,
		Side* s = new Side(vec[idx].get_name(), vec[idx].get_price(), vec[idx].get_size_diff());		//Side객체 동적 생성
		s->option();					//옵션 선택 출력
		s->set_size(input_size);		//사이즈를 set.
		cart.push_back(s);				//장바구니에 담기
	}
	else if (typeid(vec) == typeid(drink_list)) {
		Drink* d = new Drink(vec[idx].get_name(), vec[idx].get_price(), vec[idx].get_size_diff());
		d->option();					//옵션 선택 출력
		d->set_size(input_size);		//사이즈를 set.
		cart.push_back(d);				//장바구니에 담기
	}

}




/*menu.txt로부터 메뉴를 읽어오는 함수*/
void Manager::load_menu(ifstream& menu) {
	string r_name;				//읽어온 메뉴 이름
	string rs_price;			//읽어온 메뉴 가격
	string rs_size_diff;		//읽어온 사이즈별 가격차
	double r_size_diff;			//읽어온 사이즈별 가격차를 double형으로 저장하는 변수
	double r_price;				//읽어온 메뉴 가격을 double형으로 저장하는 변수
	string s;
	char ch;		//공백'\0'저장할 문자 변수

	while (menu) {
		if (menu.eof())break;		//만약 menu.txt의 끝이라면 반복문 탈출
		menu >> s;

		/*문자열 s를 읽을 때, 띄어쓰기 전까지만 읽히고, 파일에서 다음 문자열을 읽을 때, 맨 앞에 공백문자'\0'가 포함되는 문제로
		메뉴 이름이 정확히 저장되지 않는 문제점을 보완하기 위한 방법*/
		menu.get(ch);				//공백'\0'을 ch에 저장함으로써, 예를 들어 " cheese burger"가 아닌 "cheese burger"를 저장할 수 있다.
		getline(menu, r_name, ';');
		menu >> rs_price >> rs_size_diff;

		//입력받는 메뉴 가격, 사이즈별 가격차 문자열을 double형으로 변환(stod사용)
		r_size_diff = stod(rs_size_diff);
		r_price = stod(rs_price);

		if (s == "b") {				//Burger객체 생성 후 burger_list에 넣어주기.
			Burger b(r_name, r_price, r_size_diff);
			burger_list.push_back(b);
		}
		else if (s == "s") {		//Side객체 생성 후 side_list에 넣어주기.
			Side s(r_name, r_price, r_size_diff);
			side_list.push_back(s);
		}
		else if (s == "d") {		//Drink객체 생성 후 drink_list에 넣어주기.
			Drink d(r_name, r_price, r_size_diff);
			drink_list.push_back(d);
		}
	}
}




/*메뉴 주문 화면 출력*/
void Manager::order() {
	int input;
	cout << "Welcome to my Burger shop!!!" << endl;
	while (true) {
		cout << "Choose the menu you want to see." << endl;
		cout << "0 : to payment" << endl;
		cout << "1 : burgers" << endl;
		cout << "2 : sides" << endl;
		cout << "3 : drinks" << endl;

		/*정수 입력 예외처리*/
		while (true) {
			cout << "Choose num: ";
			cin >> input;
			//만약 정수가 아니거나 범위를 넘어가는 정수가 입력된다면 다시 입력
			if (!cin || (input < 0 || input > 3)) {
				cin.clear();
				cin.ignore();
			}
			else break;
		}


		switch (input)
		{
		case 0: {
			if (cart.empty()) {			//cart가 비어있다면, 장바구니에 물품이 없다고 출력
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
		if (input == 0)break;	//while문 탈출
	}
}




/*내가 새로 정의함 함수
cart의 물품들을 오버라이딩된 연산자를 이용해서 출력하는 함수*/
void Manager::my_print(vector<Food*>& pcart)const {
	for (int i = 0; i < pcart.size(); i++) {
		cout << *pcart[i];				//pcart출력
		pcart[i]->print_option();		//선택된 옵션사항도 출력
	}
}




/*영수증을 출력하는 함수*/
void Manager::receipt() {
	double total_price = 0;
	cout << endl;

	if (!cart.empty()) {		//만약 장바구니가 비어있지 않다면 영수증 출력.
		for (int i = 0; i < cart.size(); i++) {
			total_price += cart[i]->get_price();		//장바구니의 물품들의 가격 모두 더하기
		}

		cout << setw(25) << setfill(' ') << right << "==Order list==" << endl << endl;
		cout << setw(18) << setfill(' ') << right << "description";
		cout << setw(15) << setfill(' ') << right << "price";
		cout << endl << "----------------------------------------" << endl;
		my_print(cart);				//장바구니 출력
		cout << "----------------------------------------" << endl;
		cout << setw(29) << setfill(' ') << right << "Total: \\" << total_price << endl;		//총 금액 출력
	}
	cout << endl;

}




/*장바구니를 비워주는 함수*/
void Manager::clear_cart() {
	for (auto it = cart.begin(); it != cart.end();) {
		it = cart.erase(it);
	}
}