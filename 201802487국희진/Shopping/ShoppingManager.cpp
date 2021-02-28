/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "ShoppingManager.h"



/*file을 로드해온 후 읽어내기 위한 생성자*/
ShoppingManager::ShoppingManager(const string filename) {
	ifstream product;
	product.open(filename);			//file을 로드해옴.
	string r_name;					//읽어온 이름
	string rs_price;				//읽어온 가격(string형식)
	int r_price;					//정수 형식으로 변환된 읽어온 가걱
	while (product) {							//파일을 읽어오는 동안
		if (product.eof())break;				//만약 파일의 끝이라면, while문 탈출
		getline(product, r_name, ';');			//';'까지만 읽는다.
		getline(product, rs_price, '\n');		//'\n'까지만 읽는다.
		r_price = stoi(rs_price);				//정수로 변환
		//cout << "----name: " << r_name << "---price: " << r_price << endl;	//디버깅용
		Product p(r_name, r_price);				//객체 생성
		productList.push_back(p);				//productList에 객체를 넣어준다.
	}
	product.close();
}



/*메인 메뉴를 출력*/
void ShoppingManager::mainMenu() {
	int input;			//입력하는 버튼
	cout << " << INU 쇼핑에 오신 것을 환영합니다! >>" << endl;
	cout << "[1] 쇼핑 관리자 모드" << endl
		<< "[2] 고객 모드" << endl
		<< "[3] 종료" << endl;
	while (true) {
		cout << "입력: ";
		cin >> input;
		if (input < 1 || input >3) {				//없는 버튼 눌렀을 경우의 예외처리
			cout << "다시 입력하시오. " << endl;
			continue;
		}
		else break;
	}
	switch (input)
	{
	case(1): {				//input==1일 경우
		cout << endl;
		managerMode();		//관리자 모드 실행
		break;
	}
	case(2): {				//input==2일 경우
		cout << endl;
		customerMode();		//고객 모드 실행
		break;
	}
	case(3): {				//input==3일 경우, 프로그램 종료
		cout << "프로그램을 종료합니다.";
		break;
	}
	}
}



/*관리자 모드*/
void ShoppingManager::managerMode() {
	int pw = 1234;				//정해진 비밀번호는 1234
	int input_pw;				//입력하는 비밀번호
	int input;					//입력하는 버튼 번호
	while (true) {
		cout << "관리자 비밀번호를 입력하세요.(메인 화면으로 돌아가려면 -1입력) : ";
		cin >> input_pw;
		if (input_pw == -1) {			//-1을 비밀번호로 입력할 경우 메인 화면으로 돌아감.
			cout << "메인 화면으로 돌아갑니다." << endl << endl;
			mainMenu();
			break;
		}
		else if (input_pw == pw) {		//비밀번호가 일치할 경우
			break;
		}
		else if (input_pw != pw) {		//비밀번호가 일치하지 않을 경우
			cout << "비밀번호가 틀립니다!" << endl;
		}
	}
	cout << endl;

	/*여기서부터 비밀번호가 일치하는 경우만 수행*/
	if(input_pw == pw) {
		while (true) {
			cout << "< 쇼핑 관리자 모드 >" << endl;
			cout << "[1] 상품 추가" << endl
				<< "[2] 상품 삭제" << endl
				<< "[3] 모든 상품 출력" << endl
				<< "[4] 돌아가기" << endl;

			while (true) {
				cout << "입력: ";
				cin >> input;
				if (input < 1 || input > 4) {				//범위를 넘을 경우의 예외처리
					cout << "다시 입력하시오. " << endl;
					continue;
				}
				else break;
			}

			switch (input)
			{
			case(1): {					//input==1일 경우
				cout << endl;
				addProduct();			//상품 추가
				break;
			}
			case(2): {					//input==2일 경우
				cout << endl;
				deleteProduct();		//상품 삭제
				break;
			}
			case(3): {					//input==3일 경우
				cout << endl;
				print(productList);		//productList 전체 출력
				break;
			}
			case(4): {					//input==4일 경우
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


/*상품을 추가하는 함수*/
void ShoppingManager::addProduct() {
	string add_name = "NULL";			//임시 초기화 이름 값
	int add_price = 0;					//임시 초기화 가격
	Product p(add_name, add_price);		//객체 생성, stock은 입력되지 않을 경우 default 값인 100 설정
	cout << "새로운 상품을 추가합니다. 상품 입력 시 no를 입력하면 빠져나갑니다. " << endl;

	while (true) {
		bool isExist = false;		//존재하는 상품인지 아닌지를 결정하는 bool
		cin.ignore();
		cin >> p;					//연산자 오버로딩 실행

		if (p.getName() == "no") break;						//getName()이 no일 경우 상품 추가 중지

		for (int i = 0; i < productList.size(); i++) {
			if (p.getName() == productList[i].getName()) {
				isExist = true;								//이미 productList에 존재하면 isExist==true로 설정
				break;
			}
		}

		if (isExist == true) {								//이미 존재한다면
			cout << "이미 존재하는 상품입니다." << endl;
			continue;
		}
		else {												//존재하는 상품이 아니라면
			cout << p.getName() << " 을(를) 목록에 등록했습니다." << endl;
			productList.push_back(p);
		}
	}
}



/*상품 삭제 함수*/
void ShoppingManager::deleteProduct() {
	string del_name;						//삭제할 상품 이름	
	bool isExist = false;					//상품이 존재하는지 아닌지를 확인할 bool
	vector<Product>::iterator it;			//erase()를 사용하기 위한 iterator 선언
	cout << "삭제하실 상품의 이름을 입력하세요: ";
	cin >> del_name;

	for (it = productList.begin(); it != productList.end(); it++) {
		if (del_name == (*it).getName()) {			//만약 삭제할 상품이 존재한다면
			isExist = true;							//isExist==true로 설정
			productList.erase(it);					//해당 상품 삭제
			break;
		}
	}

	if (isExist == false) {							//만약 상품이 없다면
		cout << "입력하신 상품은 목록에 없습니다. " << endl << endl;
	}

	else {											//상품이 존재하므로
		cout << del_name << " 을(를) 삭제합니다." << endl << endl;
	}
}



/*상품 목록을 출력하는 함수*/
void ShoppingManager::print(vector<Product> pList) {
	for (int i = 0; i < pList.size(); i++) {
		cout << pList[i];
	}
	cout << endl << "총 " << pList.size() << "가지의 상품" << endl << endl;
}



/*고객 모드*/
void ShoppingManager::customerMode() {

	while (true) {
		int input;							//입력할 버튼 번호
		cout << "< 고객 모드 >" << endl;
		cout << "[1] 상품 보기" << endl
			<< "[2] 상품 검색" << endl
			<< "[3] 장바구니 모드" << endl
			<< "[4] 돌아가기" << endl;

		while (true) {
			cout << "입력: ";
			cin >> input;
			if (input < 1 || input >4) {
				cout << "다시 입력하시오. " << endl;
				continue;
			}
			else break;

		}


		switch (input)
		{
		case(1): {					//input==1이라면
			cout << endl;
			print(productList);		//productList출력
			break;
		}
		case(2): {					//input==2이라면
			cout << endl;
			search();				//상품 찾기
			break;
		}
		case(3): {					//input==3이라면
			cout << endl;
			cartMode();				//장바구니 모드
			break;
		}
		case(4): {					//input==4라면 돌아가기 선택
			cout << endl;	
			break;
		}
		}

		//case(3)을 수행한 뒤 수행할 코드
		if (input == 3) {		
			customerMode();
			break;
		}
		
		if (input == 4) {		//무한루프 빠져나가는 코드
			mainMenu();
			break;
		}
	}
}



/*상품을 찾는 함수*/
void ShoppingManager::search() {
	string search_name;				//찾으려는 상품 이름
	char ch;						//getline의 문제점을 해결하기 위한 문자 변수
	int index = -1;					//index의 초기값을 -1로 설정한다.

	cout << "상품명을 입력하세요: ";

	ch = cin.peek();				//먼저 엿본다.
	if (ch == '\n') {				//만약 ch=='\n'라면
		cin.ignore(1, '\n');		//ignore로 버퍼를 비운다.
	}

	getline(cin, search_name);
	for (int i = 0; i < productList.size(); i++) {
		if (search_name == productList[i].getName()) {			//존재한다면
			index = i;											//해당 인덱스값을 저장
			cout << productList[index];							//해당 인덱스 객체 출력
			cout << endl;
			break;
		}
	}
	//만약 index가 -1상태 그대로라면 찾는 상품이 없다는 의미.
	if (index == -1) {
		cout << "입력하신 상품은 현재 등록되어 있지 않습니다." << endl << endl;
	}
}



/*장바구니 모드*/
void ShoppingManager::cartMode() {
	vector<Product> cart;			//cart vector 생성
	while (true) {
		int input;					//입력하려는 버튼 번호

		cout << "< 장바구니 모드 >" << endl;
		cout << "[1] 상품 보기" << endl
			<< "[2] 장바구니에 담기" << endl
			<< "[3] 장바구니 출력" << endl
			<< "[4] 계산하기" << endl;

		while (true) {
			cout << "입력: ";
			cin >> input;
			if (input < 1 || input >4) {			//범위를 넘어갈 경우 예외 처리
				cout << "다시 입력하시오. " << endl;
				continue;
			}
			else break;
		}

		switch (input)
		{
		case(1): {						//input==1일 경우
			cout << endl;
			print(productList);			//전체 상품 출력
			break;
		}
		case(2): {						//input==2일 경우
			cout << endl;
			cart = addToCart(cart);		//장바구니에 담고 addToCart(cart)의 반환값을 다시 cart에 저장
			break;
		}
		case(3): {						//input==3일 경우
			cout << endl;
			print(cart);				//장바구니 출력
			break;
		}
		case(4): {						//input==4일 경우
			cout << endl;
			calculate(cart);			//장바구니에 담긴 상품들 계산
			cout << "장바구니 모드를 종료합니다." << endl;
			break;
		}

		}
		//case(4)를 모두 수행한 뒤 수행할 코드
		if (input == 4) {				//input==4일 경우 장바구니모드 벗어나기
			cout << endl;
			break;
		}
	}

}
	



/*장바구니에 담기*/
vector<Product> ShoppingManager::addToCart(vector<Product> pCart) {
	string want_name;				//원하는 상품 이름
	int want_stock;					//원하는 재고
	int rest_stock;					//남은 재고
	char ch;						//확인 변수
	vector<Product>::iterator it;

	while (want_name != "no") {			//"no"가 입력될 때까지 반복
		bool isExist = false;			//상품이 존재하는지 아닌지를 확인할 수 있는 bool

		cout << "구매하고자 하는 상품 이름 입력(장바구니 담기 종료는 no 입력): ";

		//getline의 문제점을 해결하기 위한 코드
		ch = cin.peek();
		if (ch == '\n') {
			cin.ignore(1, '\n');
		}

		getline(cin, want_name);
		//cout << "----want_name: " << want_name << "-------" << endl;	//디버깅용

		for (it = productList.begin(); it != productList.end(); it++) {
			if (want_name == (*it).getName()) {				//상품이 존재한다면 장바구니에 담기
				isExist = true;
				cout << "담을 수량 입력(" << want_name << "의 남은 재고: " << (*it).getStock() << "): ";

				cin >> want_stock;
				if (want_stock <= (*it).getStock()) {		//원하는 재고가 남은 재고보다 적거나 같다면 장바구니에 담기
					cout << want_name << " " << want_stock << "개를 장바구니에 담았습니다." << endl << endl;

					rest_stock = (*it).getStock() - want_stock;		//남은 재고 계산
					(*it).setStock(rest_stock);						//남은 재고 새롭게 저장

					Product pcart(want_name, (*it).getPrice(), want_stock);		//pcart객체 생성
					int tmp_index = -1;

					//장바구니에 같은 상품이 있다면 새로 객체를 pCart에 추가하지 않고 기존 객체의 재고에 want_stock을 더한다.
					for (int i = 0; i < pCart.size(); i++) {
						if (pcart.getName() == pCart[i].getName()) {			//이미 장바구니에 담은 상품이라면
							tmp_index = i;
							int new_stock = pCart[i].getStock() + pcart.getStock();		//새롭게 저장된 장바구니안 상품의 수량
							pCart[tmp_index].setStock(new_stock);
							break;
						}
					}

					if (tmp_index == -1) {			//장바구니에 없는 상품이라면
						pCart.push_back(pcart);		//pCart에 새롭게 추가
					}
				}

				else {
					cout << "재고가 부족하여 담을 수 해당 상품을 담을 수 없습니다." << endl << endl;
				}

				break;
			}
		}

		if (isExist == false) {
			cout << "입력하신 상품은 현재 등록되어 있지 않습니다." << endl << endl;
		}
	}

	return pCart;
}



/*장바구니에 있는 상품 계산 함수*/
int ShoppingManager::calculate(const vector<Product> pCart) {
	int total_price = 0;

	for (int i = 0; i < pCart.size(); i++) {
		total_price += (pCart[i].getPrice() * pCart[i].getStock());		//전체 가격 계산
		cout << pCart[i];
	}

	cout << endl;
	cout << "총 " << pCart.size() << "가지의 상품" << endl << endl;
	cout << "총 " << total_price << "원 결제 완료되었습니다." << endl;
	return total_price;
}