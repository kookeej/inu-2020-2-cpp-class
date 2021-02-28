/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef MANAGER_H
#define MANAGER_H

#include "Food.h"
#include "Burger.h"
#include "Side.h"
#include "Drink.h"



/*Manager Ŭ����*/
class Manager {
	vector<Food*> cart;					//��ٱ���
	vector<Burger> burger_list;			//�޴��� ���� ����Ʈ
	vector<Side> side_list;				//�޴��� ���̵� ����Ʈ
	vector<Drink> drink_list;			//�޴��� ���� ����Ʈ
public:
	void load_menu(ifstream& menu);		//menu.txt�κ��� �޴��� �о� ���Ϳ� �����ϴ� �Լ�
	void order();						//�ֹ� ������
	void receipt();						//������
	void clear_cart();					//��ٱ��� ����
	void my_print(vector<Food*>& pcart)const;	//�߰� �޼ҵ�. ��ٱ����� ��ǰ���� ����ϴ� �Լ�
	template <class T>
	void print_vector(T vector);		//�Լ� ���ø����� ����
	~Manager() {						//�Ҹ���. �����Ҵ�� cart����.
		for (int i = 0; i < cart.size(); i++) {
			delete cart[i];
		}
	}
};

#endif