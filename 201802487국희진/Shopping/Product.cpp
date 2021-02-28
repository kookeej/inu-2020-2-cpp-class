/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Product.h"


/*새로운 상품을 추가하기 위한 연산자 오버로딩*/
istream& operator>>(istream& ins, Product& p) {
	cout << endl;
	cout << "상품 이름 입력: ";
	getline(ins, p.name);
	if (p.name == "no") {		//만약 "no"가 입력이 되었다면 상품 추가 종료.
		cout << "새로운 상품 추가 종료" << endl << endl;
		return ins;
	}
	cout << "상품 가격 입력: ";
	ins >> p.price;
	return ins;
}



/*상품을 출력하기 위한 연산자 오버로딩, 상품 전체 출력, 장바구니 출력, 검색한 상품 출력 등 다양하게 사용됨*/
ostream& operator<<(ostream& stream, const Product& p) {
	stream << " 상품명 : " << setw(20) << setfill(' ') << left << p.name;
	stream << " 가격 : " << setw(10) << setfill(' ') << right << p.price << "원 ";
	stream << " 재고/수량 : " << p.stock << "개 " << endl;
	return stream;
}
