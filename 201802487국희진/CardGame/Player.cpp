/*201802487 ��ǻ�Ͱ��к� ������*/

#include <iostream>
using namespace std;

#include "Player.h"

//�⺻�����ڸ� �����ϸ鼭 Card��ü �迭�� �����Ѵ�.
Player::Player() {
	deck = new Card[9]{ Card(0), Card(1), Card(2), Card(3), Card(4), Card(5), Card(6), Card(7),Card(8) };
	num_card = 9;

	//ī�� ���� ��� �迭���� �ϴ� ��� 0���� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < 9; i++) {
		history[i] = 0;
	}
}

//Card�� ��ġ�� �������� ���� �迭�ϴ� �Լ�
void Player::randomShuffle() {
	//Card��ü ���� ��, ������ �����
	Card card;
	Card& tmp = card;
	int random_number;

	for (int i = 0; i < 9; i++) {
		random_number = rand() % 9;			// 0 ~ 8�� ������ ���� ���� 
		tmp = deck[i];						//�ӽ� Card��ü tmp�� deck[i]�� ����
		deck[i] = deck[random_number];		//deck[i]�� ���� �ε����� ���� deck[random_number]����
		deck[random_number] = tmp;			//deck[random_number]�� tmp ��ü ����
	}
}

//computer�� index�� �Է¹޾� �ش� �ε����� ���� ��ü�� ��ȯ�ϴ� �Լ�
Card Player::choose(const int& index) {
	Card card;
	card = deck[index];		//�Է¹��� �ε����� ���� ��ü�� �ӽ÷� �����Ѵ� ��ü card.
	//history�迭�� ī�� ���ڸ� ����
	history[9 - num_card] = deck[index].front();
	//ī�尡 ���õǾ��� ������ num_card�� 1 �پ���.
	num_card = num_card - 1;

	/* ���õ� deck[index]�� �����ϰ� �� ���� deck��ü �迭���� �� ĭ�� ������ �̵���Ű�� for �ݺ���

	|6| |4| |2| |7| |0| |5| |1| |3| |8|					<= 7����
	|6| |4| |2| |X| |0| |5| |1| |3| |8|					<= 7 ����
	|6| |4| |2| |0| |5| |1| |3| |8|						<= ������ �� ĭ�� ��� ����

	*/
	for (int i = index; i < num_card; i++) {
		//index���� ���� ī���� ������ num_card���� �ݺ��Ѵ�.
		deck[i] = deck[i + 1];			//ī�� �ε����� ������ �� ĭ�� ���� �ڵ�
	}

	/*
	����! ��ȯ�Ǵ� ī��� deck[index]�� �ƴ϶� �ʹݿ� deck[index]�� �����ߴ� card�� �����Ѵ�.
	*/
	return card;
}

//user�� number�� �Է¹޾� �ش� ī�带 ã�� �Լ�
int Player::search(const int& number) {
	int index = -1;								//index�� -1�� �ʱ�ȭ�Ѵ�. ���� -1�� ��ȯ�ȴٸ�, �ش� ���ڸ� ī�忡�� ã�� ���� ��.

	for (int i = 0; i < num_card; i++) {
		if (number == deck[i].front()) {
			history[9 - num_card] = deck[i].front();
			num_card = num_card - 1;
			index = i;							//index�� �Է¹��� ���ڰ� �����ϴ� deck�� �ε����� ����
			for (int j = index; j < num_card; j++) {
				deck[j] = deck[j + 1];
			}
			break;								//���� ���ڿ� �ش��ϴ� ī�带 ã�Ҵٸ� �� �̻� �ݺ����� �������� �ʴ´�.
		}
		else continue;
	}
	return index;
}

//ī���� �ո�(����)�� ������ִ� �Լ�
void Player::printFront()const {
	for (int i = 0; i < num_card; i++) {
		cout << " _    ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << "|" << deck[i].front() << "|   ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << " -    ";
	}
	cout << endl;
}

//ī���� �޸�(����)�� ������ִ� �Լ�
void Player::printBack()const {
	for (int i = 0; i < num_card; i++) {
		cout << " _    ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << "|" << deck[i].back() << "|   ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << " -    ";
	}
	cout << endl;
}

//history�迭�� ������ִ� �Լ�
void Player::printHistory()const {
	for (int i = 0; i < 9; i++) {
		cout << history[i] << " ";
	}
	cout << endl;
}