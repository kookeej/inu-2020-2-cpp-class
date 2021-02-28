/*201802487 컴퓨터공학부 국희진*/

#include "Time.h"
#include <iostream>
using namespace std;

int main() {
	char tmp[100];		//처음에 입력받을 시간을 저장할 문자열이다.
	char* colon;		//':'을 의미한다.
	char* context;		
	int h, m, s;		//각각 시간, 분, 초를 저장할 변수
	int add;			//증가시킬 초를 입력받는 변수


	//getline()으로 문자열로 나타내어진 시간을 입력 받는다.
	cout << "시간을 입력하세요: ";
	cin.getline(tmp, 100);

	int colon_cnt = 0;		//콜론(:)의 개수에 따라서 처리 방식이 달라지므로 콜론을 세어줄 변수를 선언
	
	//입력받은 문자열의 길이만큼 문자 하나씩 검토하며 콜론이 있는지 점검
	for (int i = 0; i < strlen(tmp); i++) {
		if (tmp[i] == ':') {	//만약 존재한다면, 콜론의 개수를 더해준다.
			colon_cnt++;
		}
	}

	/*만약 콜론의 개수가 0개라면, '시'만 입력 받은 것
	따라서 생성자 Time(int h)를 사용해야 함. 
	*/
	if (colon_cnt == 0) {
		h = atoi(strtok_s(tmp, "", &context));
		Time time(h);
		cout << "몇 초의 시간을 증가시키겠습니까? ";
		cin >> add;
		for (int i = 1; i <= add; i++) time.tick();
		time.print();
	}

	/*
	만약 콜론의 개수가 1개라면, '시'와 '분'을 입력 받은 것
	생성자 Time(int h, int m)을 사용해야 함.
	*/
	else if (colon_cnt == 1) {
		h = atoi(strtok_s(tmp, ":", &context));
		m = atoi(strtok_s(NULL, "", &context));
		Time time(h, m);
		cout << "몇 초의 시간을 증가시키겠습니까? ";
		cin >> add;
		for (int i = 1; i <= add; i++) time.tick();
		time.print();
	}

	/*
	만약 콜론의 개수가 2개라면 '시','분','초'를 모두 입력 받은 것
	생성자 Time(int h, int m, int s)을 사용해야 함.
	*/
	else if (colon_cnt == 2) {
		h = atoi(strtok_s(tmp, ":", &context));
		m = atoi(strtok_s(NULL, ":", &context));
		s = atoi(strtok_s(NULL, "", &context));
		Time time(h, m, s);
		cout << "몇 초의 시간을 증가시키겠습니까? ";
		cin >> add;
		for (int i = 1; i <= add; i++) time.tick();
		time.print();
	}
}