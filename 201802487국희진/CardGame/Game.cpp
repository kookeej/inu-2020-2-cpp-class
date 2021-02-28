/*201802487 컴퓨터공학부 국희진*/

#include <iostream>
using namespace std;

#include "Game.h"

//Game의 기본생성자
Game::Game() {
	computer = new Player();
	user = new Player();
	this->round = 1;
	this->comp_first = true;		//computer가 먼저 시작하도록 하기 위해서
	this->user_win = 0;
	this->comp_win = 0;
}


void Game::play() {
	computer->randomShuffle();			//computer의 카드를 무작위로 섞어 배열
	while (round < 10) {				//round=9가 될 때까지 반복
		advanceRound();
		round += 1;
	}

	//모든 라운드가 끝이 났을 때 출력
	cout << "========================================" << endl;
	cout << "All rounds have ended" << endl;
	cout << "========================================" << endl;

	//user가 이긴 횟수, computer가 이긴 횟수를 출력
	cout << "user won " << user_win << " times" << endl;
	cout << "computer won " << comp_win << " times" << endl;

	//결과적으로 user와 computer 중 누가 이겼는지 찾는 코드
	if (user_win > comp_win) {									//user가 이겼을 때
		cout << "Congratulations! You won!! :)" << endl;
	}
	else if (user_win < comp_win) {								//computer가 이겼을 때
		cout << "Computer won!! :(" << endl;
	}
	else {														//비겼을 때
		cout << "Finish a tie!! :o" << endl;
	}

	//user와 computer의 history를 출력
	cout << endl;
	cout << "user history      : ";
	user->printHistory();
	cout << "computer history  : ";
	computer->printHistory();

}

void Game::advanceRound() {

	//라운드, 카드 출력 코드 시작
	cout << "========================================" << endl;
	cout << "Round : " << round << endl;
	cout << "========================================" << endl;
	cout << "<computer cards>" << endl;
	computer->printBack();
	cout << endl;
	cout << "<user cards>" << endl;
	user->printFront();
	cout << endl;
	//라운드, 카드 출력 코드 끝

	//computer의 카드 객체를 임시로 저장할 c 생성. 참조자 comp사용.
	Card c;
	Card& comp = c;

	//참조자 사용
	int a = 10;
	int& user_choose = a;
	int b = 10;
	int& user_idex = b;


	if (comp_first == true) {					//comp_first == true일 때, computer먼저 카드 선택

		//computer 차례
		cout << "computer's turn!" << endl;
		cout << "                  _" << endl;
		cout << "computer chose : ";

		int comp_index = rand() % (10 - round);		//comp_index를 0에서 남은 카드 개수 사이의 랜덤한 정수 생성

		//객체 참조자 comp에 computer가 선택한 객체 저장
		comp = computer->choose(comp_index);
		int computer_choose = comp.front();			//컴퓨터 카드의 숫자를 computer_choose에 저장

		cout << "|" << comp.back() << "|" << endl;
		cout << "                  - " << endl << endl;

		//user차례
		cout << "Your turn!" << endl;
		//user가 존재하는 카드 숫자를 선택할 때까지 반복
		//search()에서 반환된 인덱스가 -1이면 존재하지 않는 카드숫자
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
				break;												//반복문 탈출
			}
		}

		//user가 이겼을 때
		if (user_choose > computer_choose) {
			user_win += 1;
			comp_first = false;
			cout << ">>>>>> user won!" << endl << endl;
		}

		//무승부일 때
		else if (user_choose == computer_choose) {
			cout << ">>>>>> Tie!" << endl << endl;			//무승부
		}
		//computer가 이겼을 때
		else {
			comp_win += 1;
			comp_first = true;
			cout << ">>>>>> computer won!" << endl << endl;
		}

	}

	//user가 먼저 선택하는 경우
	else {														//comp_first == false일 때, user먼저 카드 선택
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