/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include "Time.h"
using namespace std;

Time::Time() :Time(0, 0, 0) {}
Time::Time(int h) :Time(h, 0, 0) {}
Time::Time(int h, int m) : Time(h, m, 0) {}
Time::Time(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

//증가 후 시각을 프린트 해주는 함수
void Time::print() {
	cout << "증가 후 시각: " << "("<< hour << ":" << minute << ":"<< second << ")";
}

//1초가 증가한 후의 시각을 계산해주는 함수
void Time::tick() {
	//tick()이 호출되면 기존의 초에 1을 더하는 연산을 수행한다.
	second = second + 1;

	//만약 저장된 '초'가 60보다 크거나 같을 경우
	if (second >= 60) {
		second = second % 60;
		minute = minute + 1;
	}

	//만약 저장된 '분'이 60보다 크거나 같을 경우
	if (minute >= 60) {
		minute = minute % 60;
		hour = hour + 1;
	}

	//만약 저장된 '시'가 24보다 크거나 같을 경우
	if (hour >= 24) {
		hour = hour % 24;
	}
}
