/*201802487 컴퓨터공학부 국희진*/

#ifndef MANAGER_H
#define MANAGER_H

#include "Food.h"
#include "Burger.h"
#include "Side.h"
#include "Drink.h"



/*Manager 클래스*/
class Manager {
	vector<Food*> cart;					//장바구니
	vector<Burger> burger_list;			//메뉴의 버거 리스트
	vector<Side> side_list;				//메뉴의 사이드 리스트
	vector<Drink> drink_list;			//메뉴의 음료 리스트
public:
	void load_menu(ifstream& menu);		//menu.txt로부터 메뉴를 읽어 벡터에 저장하는 함수
	void order();						//주문 페이지
	void receipt();						//영수증
	void clear_cart();					//장바구니 비우기
	void my_print(vector<Food*>& pcart)const;	//추가 메소드. 장바구니의 물품들을 출력하는 함수
	template <class T>
	void print_vector(T vector);		//함수 템플릿으로 구현
	~Manager() {						//소멸자. 동적할당된 cart비우기.
		for (int i = 0; i < cart.size(); i++) {
			delete cart[i];
		}
	}
};

#endif