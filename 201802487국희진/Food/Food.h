/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef FOOD_H
#define FOOD_H


enum class Size { SMALL, MEDIUM, LARGE };


class Food {
	double base_price;		//�⺻ �ݾ�(MEDIUM�� ��)
	string name;			//�޴� �̸�
	double size_diff;		//����� ������
	Size size;				//������
public:
	void set_size(const int i);		//������ ����	
	double get_price()const {		//���� ����
		return base_price;
	}
	double get_size_diff()const {	//����� ������ ����
		return size_diff;
	}
	string get_name()const {			//�޴� �̸� ����	
		return name;
	}
	Size get_size()const {			//������ ����
		return size;
	}
	virtual void option() = 0;
	virtual void print_option() = 0;
	Food(string name, double price, double size_diff) {		//������ �Ű������� ���� ������
		base_price = price;
		this->name = name;
		this->size_diff = size_diff;
		size = Size::MEDIUM;				//�⺻ ������� MEDIUM
	}
	virtual ~Food() { }			//Food�Ҹ���
	friend ostream& operator<<(ostream& os, const Food& f);
};

#endif