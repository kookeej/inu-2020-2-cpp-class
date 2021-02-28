/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
using namespace std;

#include "Game.h"

//Game�� �⺻������
Game::Game() {
	computer = new Player();
	user = new Player();
	this->round = 1;
	this->comp_first = true;		//computer�� ���� �����ϵ��� �ϱ� ���ؼ�
	this->user_win = 0;
	this->comp_win = 0;
}


void Game::play() {
	computer->randomShuffle();			//computer�� ī�带 �������� ���� �迭
	while (round < 10) {				//round=9�� �� ������ �ݺ�
		advanceRound();
		round += 1;
	}

	//��� ���尡 ���� ���� �� ���
	cout << "========================================" << endl;
	cout << "All rounds have ended" << endl;
	cout << "========================================" << endl;

	//user�� �̱� Ƚ��, computer�� �̱� Ƚ���� ���
	cout << "user won " << user_win << " times" << endl;
	cout << "computer won " << comp_win << " times" << endl;

	//��������� user�� computer �� ���� �̰���� ã�� �ڵ�
	if (user_win > comp_win) {									//user�� �̰��� ��
		cout << "Congratulations! You won!! :)" << endl;
	}
	else if (user_win < comp_win) {								//computer�� �̰��� ��
		cout << "Computer won!! :(" << endl;
	}
	else {														//����� ��
		cout << "Finish a tie!! :o" << endl;
	}

	//user�� computer�� history�� ���
	cout << endl;
	cout << "user history      : ";
	user->printHistory();
	cout << "computer history  : ";
	computer->printHistory();

}

void Game::advanceRound() {

	//����, ī�� ��� �ڵ� ����
	cout << "========================================" << endl;
	cout << "Round : " << round << endl;
	cout << "========================================" << endl;
	cout << "<computer cards>" << endl;
	computer->printBack();
	cout << endl;
	cout << "<user cards>" << endl;
	user->printFront();
	cout << endl;
	//����, ī�� ��� �ڵ� ��

	//computer�� ī�� ��ü�� �ӽ÷� ������ c ����. ������ comp���.
	Card c;
	Card& comp = c;

	//������ ���
	int a = 10;
	int& user_choose = a;
	int b = 10;
	int& user_idex = b;


	if (comp_first == true) {					//comp_first == true�� ��, computer���� ī�� ����

		//computer ����
		cout << "computer's turn!" << endl;
		cout << "                  _" << endl;
		cout << "computer chose : ";

		int comp_index = rand() % (10 - round);		//comp_index�� 0���� ���� ī�� ���� ������ ������ ���� ����

		//��ü ������ comp�� computer�� ������ ��ü ����
		comp = computer->choose(comp_index);
		int computer_choose = comp.front();			//��ǻ�� ī���� ���ڸ� computer_choose�� ����

		cout << "|" << comp.back() << "|" << endl;
		cout << "                  - " << endl << endl;

		//user����
		cout << "Your turn!" << endl;
		//user�� �����ϴ� ī�� ���ڸ� ������ ������ �ݺ�
		//search()���� ��ȯ�� �ε����� -1�̸� �������� �ʴ� ī�����
		while (true) {
			cout << "Which Card will you choose? ";
			cin >> user_choose;
			
			user_idex = user->search(user_choose);
			if (user_idex == -1) {
				cout << "No " << user_choose << " in deck!" << endl;
			}

			else {
				cout << "              _" << endl;
				cout << "user chose : ";
				cout << "|" << user_choose << "|" << endl;
				cout << "              -" << endl;
				break;												//�ݺ��� Ż��
			}
		}

		//user�� �̰��� ��
		if (user_choose > computer_choose) {
			user_win += 1;
			comp_first = false;
			cout << ">>>>>> user won!" << endl << endl;
		}

		//���º��� ��
		else if (user_choose == computer_choose) {
			cout << ">>>>>> Tie!" << endl << endl;			//���º�
		}
		//computer�� �̰��� ��
		else {
			comp_win += 1;
			comp_first = true;
			cout << ">>>>>> computer won!" << endl << endl;
		}

	}

	//user�� ���� �����ϴ� ���
	else {														//comp_first == false�� ��, user���� ī�� ����
		cout << "Your turn!" << endl;
		while (true) {
			cout << "Which Card will you choose? ";
			cin >> user_choose;
			user_idex = user->search(user_choose);
			if (user_idex == -1) {
				cout << "No " << user_choose << " in deck!" << endl;
			}
			else {
				cout << "              _" << endl;
				cout << "user chose : ";
				cout << "|" << user_choose << "|" << endl;
				cout << "              -" << endl;
				break;
			}
		}
		cout << "computer's turn!" << endl;
		cout << "                  _" << endl;
		cout << "computer chose : ";
		int comp_index = rand() % (10 - round);
		comp = computer->choose(comp_index);
		int computer_choose = comp.front();

		cout << "|" << comp.back() << "|" << endl;
		cout << "                  - " << endl;

		if (user_choose > computer_choose) {
			user_win += 1;
			comp_first = false;
			cout << ">>>>>> user won!" << endl;
		}
		else if (user_choose == computer_choose) {
			user_win += 0;
			comp_win += 0;
			cout << ">>>>>> Tie!" << endl;
		}
		else {
			comp_win += 1;
			comp_first = true;
			cout << ">>>>>> computer won!" << endl;
		}

	}
}