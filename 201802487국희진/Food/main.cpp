/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "Manager.h"

int main() {
	Manager m;
	ifstream menu("menu.txt");
	m.load_menu(menu);
	menu.close();
	while (1) {
		m.order();
		m.receipt();
		char c;
		cout << "New Order? (y or n) ";
		cin >> c;
		if (c == 'n')
			return 0;
		m.clear_cart();
	}
}