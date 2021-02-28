/*201802487 컴퓨터공학부 국희진*/

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