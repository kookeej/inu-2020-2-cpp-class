/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "ShoppingManager.h"

int main(void)
{
	ShoppingManager sm("product.txt");
	sm.mainMenu();
	return 0;
}