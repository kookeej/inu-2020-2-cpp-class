/*201802487 ��ǻ�Ͱ��к� ������*/
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