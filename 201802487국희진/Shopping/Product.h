/*201802487 ��ǻ�Ͱ��к� ������*/

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
	//getter, setter�Լ�
	void setName(string name) {		//�̸� set
		this->name = name;
	}
	void setPrice(int price) {		//���� set
		this->price = price;
	}
	void setStock(int stock) {		//��� set
		this->stock = stock;
	}
	string getName()const {			//�̸� return
		return name;
	}
	int getPrice()const {			//���� return
		return price;
	}
	int getStock()const {			//��� return
		return stock;
	}

	friend istream& operator>>(istream& ins, Product& p);				//���ο� ��ǰ�� �߰��ϱ� ���� ���� ������ �����ε�
	friend ostream& operator<<(ostream& stream, const Product& p);		//��ǰ�� ����ϴ� ������ �����ε�
};

#endif