/*201802487 컴퓨터공학부 국희진*/

#ifndef FOOD_H
#define FOOD_H


enum class Size { SMALL, MEDIUM, LARGE };


class Food {
	double base_price;		//기본 금액(MEDIUM일 때)
	string name;			//메뉴 이름
	double size_diff;		//사이즈별 가격차
	Size size;				//사이즈
public:
	void set_size(const int i);		//사이즈 설정	
	double get_price()const {		//가격 리턴
		return base_price;
	}
	double get_size_diff()const {	//사이즈별 가격차 리턴
		return size_diff;
	}
	string get_name()const {			//메뉴 이름 리턴	
		return name;
	}
	Size get_size()const {			//사이즈 리턴
		return size;
	}
	virtual void option() = 0;
	virtual void print_option() = 0;
	Food(string name, double price, double size_diff) {		//디폴드 매개변수를 가진 생성자
		base_price = price;
		this->name = name;
		this->size_diff = size_diff;
		size = Size::MEDIUM;				//기본 사이즈는 MEDIUM
	}
	virtual ~Food() { }			//Food소멸자
	friend ostream& operator<<(ostream& os, const Food& f);
};

#endif