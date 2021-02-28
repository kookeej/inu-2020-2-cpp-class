/*201802487 컴퓨터공학부 국희진*/

#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
	string name;
	int price;
	int stock;
public:
	Product(string name, int price, int stock = 100) {
		this->name = name;
		this->price = price;
		this->stock = stock;
	}
	//getter, setter함수
	void setName(string name) {		//이름 set
		this->name = name;
	}
	void setPrice(int price) {		//가격 set
		this->price = price;
	}
	void setStock(int stock) {		//재고 set
		this->stock = stock;
	}
	string getName()const {			//이름 return
		return name;
	}
	int getPrice()const {			//가격 return
		return price;
	}
	int getStock()const {			//재고 return
		return stock;
	}

	friend istream& operator>>(istream& ins, Product& p);				//새로운 상품을 추가하기 위해 쓰는 연산자 오버로딩
	friend ostream& operator<<(ostream& stream, const Product& p);		//상품을 출력하는 연산자 오버로딩
};

#endif