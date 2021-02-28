/*201802487 ��ǻ�Ͱ��к� ������*/

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

//���� �� �ð��� ����Ʈ ���ִ� �Լ�
void Time::print() {
	cout << "���� �� �ð�: " << "("<< hour << ":" << minute << ":"<< second << ")";
}

//1�ʰ� ������ ���� �ð��� ������ִ� �Լ�
void Time::tick() {
	//tick()�� ȣ��Ǹ� ������ �ʿ� 1�� ���ϴ� ������ �����Ѵ�.
	second = second + 1;

	//���� ����� '��'�� 60���� ũ�ų� ���� ���
	if (second >= 60) {
		second = second % 60;
		minute = minute + 1;
	}

	//���� ����� '��'�� 60���� ũ�ų� ���� ���
	if (minute >= 60) {
		minute = minute % 60;
		hour = hour + 1;
	}

	//���� ����� '��'�� 24���� ũ�ų� ���� ���
	if (hour >= 24) {
		hour = hour % 24;
	}
}
