/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef SHOPPINGMANAGER_H
#define SHOPPINGMANAGER_H
#include "Product.h"

class ShoppingManager {
	vector<Product> productList;
public:
	ShoppingManager(const string filename);		//file�� �ε��ؿͼ� �о�� ���� ������

	//In mainMenue
	void mainMenu();					//���� �޴�
	void managerMode();					//������ ���
	void customerMode();				//�� ���

	//In managerMenu
	void addProduct();					//��ǰ �߰�
	void deleteProduct();				//��ǰ ����
	void print(vector<Product> pList);	//��ǰ ��ü ���

	//In customerMenu
	void search();						//��ǰ �˻�
	void cartMode();					//��ٱ��� ���
	vector<Product> addToCart(vector<Product>);		//��ٱ��Ͽ� �߰�
	int calculate(const vector<Product>);			//���
};

#endif