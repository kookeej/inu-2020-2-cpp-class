/*201802487 ��ǻ�Ͱ��к� ������*/

#include "Time.h"
#include <iostream>
using namespace std;

int main() {
	char tmp[100];		//ó���� �Է¹��� �ð��� ������ ���ڿ��̴�.
	char* colon;		//':'�� �ǹ��Ѵ�.
	char* context;		
	int h, m, s;		//���� �ð�, ��, �ʸ� ������ ����
	int add;			//������ų �ʸ� �Է¹޴� ����


	//getline()���� ���ڿ��� ��Ÿ������ �ð��� �Է� �޴´�.
	cout << "�ð��� �Է��ϼ���: ";
	cin.getline(tmp, 100);

	int colon_cnt = 0;		//�ݷ�(:)�� ������ ���� ó�� ����� �޶����Ƿ� �ݷ��� ������ ������ ����
	
	//�Է¹��� ���ڿ��� ���̸�ŭ ���� �ϳ��� �����ϸ� �ݷ��� �ִ��� ����
	for (int i = 0; i < strlen(tmp); i++) {
		if (tmp[i] == ':') {	//���� �����Ѵٸ�, �ݷ��� ������ �����ش�.
			colon_cnt++;
		}
	}

	/*���� �ݷ��� ������ 0�����, '��'�� �Է� ���� ��
	���� ������ Time(int h)�� ����ؾ� ��. 
	*/
	if (colon_cnt == 0) {
		h = atoi(strtok_s(tmp, "", &context));
		Time time(h);
		cout << "�� ���� �ð��� ������Ű�ڽ��ϱ�? ";
		cin >> add;
		for (int i = 1; i <= add; i++) time.tick();
		time.print();
	}

	/*
	���� �ݷ��� ������ 1�����, '��'�� '��'�� �Է� ���� ��
	������ Time(int h, int m)�� ����ؾ� ��.
	*/
	else if (colon_cnt == 1) {
		h = atoi(strtok_s(tmp, ":", &context));
		m = atoi(strtok_s(NULL, "", &context));
		Time time(h, m);
		cout << "�� ���� �ð��� ������Ű�ڽ��ϱ�? ";
		cin >> add;
		for (int i = 1; i <= add; i++) time.tick();
		time.print();
	}

	/*
	���� �ݷ��� ������ 2����� '��','��','��'�� ��� �Է� ���� ��
	������ Time(int h, int m, int s)�� ����ؾ� ��.
	*/
	else if (colon_cnt == 2) {
		h = atoi(strtok_s(tmp, ":", &context));
		m = atoi(strtok_s(NULL, ":", &context));
		s = atoi(strtok_s(NULL, "", &context));
		Time time(h, m, s);
		cout << "�� ���� �ð��� ������Ű�ڽ��ϱ�? ";
		cin >> add;
		for (int i = 1; i <= add; i++) time.tick();
		time.print();
	}
}