/*201802487 컴퓨터공학부 국희진*/

#ifndef TIME_H
#define TIME_H

class Time {
	int hour, minute, second;
public:
	Time();
	Time(int h);
	Time(int h, int m);
	Time(int h, int m, int s);
	void print();
	void tick();
};

#endif