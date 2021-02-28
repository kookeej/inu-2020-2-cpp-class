/*201802487 컴퓨터공학부 국희진*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Hotel.h"

int main()
{
	ifstream setting("setting.txt");
	Hotel h(setting);
	setting.close();
	ifstream fin("input.txt");
	h.open(fin);
	fin.close();

	return 0;

}