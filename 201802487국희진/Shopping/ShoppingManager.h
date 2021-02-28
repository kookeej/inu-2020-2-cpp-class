/*201802487 컴퓨터공학부 국희진*/

#ifndef SHOPPINGMANAGER_H
#define SHOPPINGMANAGER_H
#include "Product.h"

class ShoppingManager {
	vector<Product> productList;
public:
	ShoppingManager(const string filename);		//file을 로드해와서 읽어내기 위한 생성자

	//In mainMenue
	void mainMenu();					//메인 메뉴
	void managerMode();					//관리자 모드
	void customerMode();				//고객 모드

	//In managerMenu
	void addProduct();					//상품 추가
	void deleteProduct();				//상품 삭제
	void print(vector<Product> pList);	//상품 전체 출력

	//In customerMenu
	void search();						//상품 검색
	void cartMode();					//장바구니 모드
	vector<Product> addToCart(vector<Product>);		//장바구니에 추가
	int calculate(const vector<Product>);			//계산
};

#endif