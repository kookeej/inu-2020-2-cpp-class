/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
using namespace std;

#include "Player.h"

//기본생성자를 실행하면서 Card객체 배열을 생성한다.
Player::Player() {
	deck = new Card[9]{ Card(0), Card(1), Card(2), Card(3), Card(4), Card(5), Card(6), Card(7),Card(8) };
	num_card = 9;

	//카드 숫자 기록 배열에는 일단 모두 0으로 초기화한다.
	for (int i = 0; i < 9; i++) {
		history[i] = 0;
	}
}

//Card의 위치를 랜덤으로 섞어 배열하는 함수
void Player::randomShuffle() {
	//Card객체 생성 후, 참조자 만들기
	Card card;
	Card& tmp = card;
	int random_number;

	for (int i = 0; i < 9; i++) {
		random_number = rand() % 9;			// 0 ~ 8의 임의의 정수 생성 
		tmp = deck[i];						//임시 Card객체 tmp에 deck[i]를 저장
		deck[i] = deck[random_number];		//deck[i]에 랜덤 인덱스를 갖는 deck[random_number]저장
		deck[random_number] = tmp;			//deck[random_number]에 tmp 객체 저장
	}
}

//computer가 index를 입력받아 해당 인덱스를 갖는 객체를 반환하는 함수
Card Player::choose(const int& index) {
	Card card;
	card = deck[index];		//입력받은 인덱스를 갖는 객체를 임시로 저장한는 객체 card.
	//history배열에 카드 숫자를 저장
	history[9 - num_card] = deck[index].front();
	//카드가 선택되었기 때문에 num_card는 1 줄어든다.
	num_card = num_card - 1;

	/* 선택된 deck[index]를 제거하고 그 뒤의 deck객체 배열들을 한 칸씩 앞으로 이동시키는 for 반복문

	|6| |4| |2| |7| |0| |5| |1| |3| |8|					<= 7선택
	|6| |4| |2| |X| |0| |5| |1| |3| |8|					<= 7 제거
	|6| |4| |2| |0| |5| |1| |3| |8|						<= 앞으로 한 칸씩 모두 당기기

	*/
	for (int i = index; i < num_card; i++) {
		//index에서 남은 카드의 개수인 num_card까지 반복한다.
		deck[i] = deck[i + 1];			//카드 인덱스를 앞으로 한 칸씩 당기는 코드
	}

	/*
	주의! 반환되는 카드는 deck[index]가 아니라 초반에 deck[index]를 저장했던 card를 리턴한다.
	*/
	return card;
}

//user가 number를 입력받아 해당 카드를 찾는 함수
int Player::search(const int& number) {
	int index = -1;								//index를 -1로 초기화한다. 만약 -1이 반환된다면, 해당 숫자를 카드에서 찾지 못한 것.

	for (int i = 0; i < num_card; i++) {
		if (number == deck[i].front()) {
			history[9 - num_card] = deck[i].front();
			num_card = num_card - 1;
			index = i;							//index에 입력받은 숫자가 존재하는 deck의 인덱스를 저장
			for (int j = index; j < num_card; j++) {
				deck[j] = deck[j + 1];
			}
			break;								//만약 숫자에 해당하는 카드를 찾았다면 더 이상 반복문을 실행하지 않는다.
		}
		else continue;
	}
	return index;
}

//카드의 앞면(숫자)를 출력해주는 함수
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

//카드의 뒷면(색깔)을 출력해주는 함수
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

//history배열을 출력해주는 함수
void Player::printHistory()const {
	for (int i = 0; i < 9; i++) {
		cout << history[i] << " ";
	}
	cout << endl;
}