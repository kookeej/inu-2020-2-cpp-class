/*201802487 컴퓨터공학부 국희진*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Hotel.h"
#include "Room.h"
#include "Standard.h"
#include "Suite.h"
#include "Royal.h"


//사용자 정의 연산자. log<<RoomType 수행
ofstream& operator<<(ofstream& log, RoomType& rt) {

	if (rt == RoomType::STANDARD) {
		log << "Standard Room ";
	}
	else if (rt == RoomType::SUITE) {
		log << "Suite Room ";
	}
	else if (rt == RoomType::ROYAL) {
		log << "Royal Room ";
	}

	return log;
}


//Hotel 생성자
Hotel::Hotel(ifstream& setting) {
	string line;
	string type;		//RoomType을 입력받을 변수
	int rn;				//Room Number를 입력받을 변수

	getline(setting, line);		//시간 입력받음
	time = stoi(line);

	getline(setting, line);		//호텔 방 개수 입력받음
	size = stoi(line);

	rooms = new Room * [size];			//객체 배열 생성
	roomTypes = new RoomType[size];

	int i = 0;
	while (setting) {					//setting.txt를 읽는다.
		setting >> type >> rn;			//type과 room number를 읽는다.

		if (type == "s") {
			roomTypes[i] = RoomType::STANDARD;
			rooms[i] = new Standard(rn);
		}
		else if (type == "u") {
			roomTypes[i] = RoomType::SUITE;
			rooms[i] = new Suite(rn);
		}
		else if (type == "r") {
			roomTypes[i] = RoomType::ROYAL;
			rooms[i] = new Royal(rn);
		}

		i += 1;
	}
}



/*해당 룸넘버를 갖고 있는 rooms의 인덱스를 반환하는 함수*/
int Hotel::room_to_i(const int rn) {		//rn: Room Number
	int index;
	for (index = 0; index < size; index++) {
		if (rooms[index]->getRoomNum() == rn) {
			return index;
		}
	}
	return -1;
}



/*파일 fin을 열어 읽는 함수*/
void Hotel::open(ifstream& fin) {
	ofstream log("log.txt");						//문자를 입력받을 log.txt를 연다.
	log << "Time: " << time << ":00" << endl;
	log << "Hotel opened." << endl;
	string c;
	while (fin) {
		if (fin.eof()) break;						//만약 파일의 끝이라면 반복문을 멈춘다.

		fin >> c;									//문자열 c를 읽는다.

		switch (c[0])
		{
		case ('i'): {			//c[0]==i일 때
			string is;
			fin >> is;

			string name;
			int people_num;
			int breakfast_num;

			fin >> name;
			fin >> people_num;
			fin >> breakfast_num;



			switch (is[0])
			{

			case ('s'): {			//is[0]==s일 때, Standard로 checkin
				int idx = -1;			//인덱스를 저장할 변수
				int other_num;		//'그 외 인원'을 저장할 변수
				for (int k = 0; k < size; k++) {
					//Standard이고 비어있는 방을 찾는다.
					if (roomTypes[k] == RoomType::STANDARD && rooms[k]->getState() == State::EMPTY) {
						idx = k;		//찾은 인덱스 값을 idx에 대입하여 저장
						break;
					}
					
				}
				if (idx == -1) {
					cout << "Standard Room not available" << endl;
					log << "Standard Room not available" << endl;
					break;
				}

				//checkin함수를 이용해 초기화
				rooms[idx]->checkin(name, people_num, breakfast_num);
				//State를 Occupied로 설정
				rooms[idx]->setState(State::OCCUPIED);
				other_num = people_num - 1;
				log << "Checked in to Standard Room ";
				log << (Room&)*rooms[idx] << endl;

				break;
			}

			case ('u'): {				//is[0]==u일 때, Suite로 checkin
				//설명은 위와 동일
				int idx = -1;
				int other_num;
				for (int k = 0; k < size; k++) {
					if (roomTypes[k] == RoomType::SUITE && rooms[k]->getState() == State::EMPTY) {
						idx = k;
						break;
					}
				}
				if (idx == -1) {
					cout << "Suite Room not available" << endl;
					log << "Suite Room not available" << endl;
					break;
				}

				rooms[idx]->checkin(name, people_num, breakfast_num);
				rooms[idx]->setState(State::OCCUPIED);
				other_num = people_num - 1;
				log << "Checked in to Suite Room ";
				log << (Room&)*rooms[idx] << endl;

				break;
			}

			case ('r'): {				//is[0]==r일 때, Royal에 checkin
				int idx = -1;
				int other_num;
				for (int k = 0; k < size; k++) {
					if (roomTypes[k] == RoomType::ROYAL && rooms[k]->getState() == State::EMPTY) {
						idx = k;
						break;
					}
				}
				if (idx == -1) {
					cout << "Royal Room not available" << endl;
					log << "Royal Room not available" << endl;
					break;
				}

				rooms[idx]->checkin(name, people_num, breakfast_num);
				rooms[idx]->setState(State::OCCUPIED);
				other_num = people_num - 1;
				log << "Checked in to Royal Room ";
				log << (Room&)*rooms[idx] << endl;

				break;
			}

			default:
				cout << "----------error----------" << endl;
			}

			break;
		}

		case ('o'): {				//c[0]==o일 때, check out 수행
			int out_room_num;		//check-out하려는 방의 룸넘버를 가리키는 변수
			fin >> out_room_num;

			int idx = room_to_i(out_room_num);		//해당 룸넘버를 갖고 있는 객체배열의 인덱스를 구한다.
			if (rooms[idx]->getState() != State::OCCUPIED) {
				cout << "check-out error: Room " << out_room_num << " is Empty" << endl;
				log << "check-out error: Room " << out_room_num << " is Empty" << endl;
				break;
			}

			//전체 금액 = calculate에서 반환한 금액 + serviceCost를 더한다.
			//getServiceCost가 반환한 serviceCost에는 room service에 대한 추가 금액도 갖고 있다. 
			int RoomTotalCost = rooms[idx]->calculate() + rooms[idx]->getServiceCost();

			log << roomTypes[idx];
			log << (Room&)*rooms[idx] << " checked out." << endl;
			log << "&" << RoomTotalCost << " added to the total income." << endl;

			rooms[idx]->checkout();		//rooms[idx]에 대한 checkout()수행.
			totalIncome += RoomTotalCost;	//check-out동작 수행 후, 전체 수익에 해당 Room 수익을 더해준다.

			break;
		}
		case ('p'): {
			for (int k = 0; k < size; k++) {
				int RoomTotalCost = rooms[k]->calculate() + rooms[k]->getServiceCost();
				log << roomTypes[k];

				//만약 Occupied 상태라면, 지금까지 발생한 비용을 함께 출력해준다.
				if (rooms[k]->getState() == State::OCCUPIED) {
					log << (Room&)*rooms[k] << " $" << RoomTotalCost << " expected" << endl;
				}
				else {
					log << (Room&)*rooms[k] << endl;
				}

			}

			break;
		}

		case ('a'): {		//c[0]==a일 때, 한 시간 경과
			++time;
			if (time >= 24) {
				time = time - 24;		//0~23까지 돌아가도록 한다.
			}

			//시간 지날 때마다 prepare()이 수행되므로 'a'를 읽음과 동시에 prepare()도 함께 수행
			for (int k = 0; k < size; k++) {
				//만약 Preparing상태라면 prepare()를 수행
				if (rooms[k]->getState() == State::PREPARING) {
					rooms[k]->prepare();
					break;
				}
			}

			log << endl;
			log << "Time: " << time << ":00" << endl;
			break;
		}

		case ('s'): {					//c[0]==s 일 때, Room service 수행
			int find_room_num;			//찾을 룸넘버
			int roomservice_cost;		//room servie 비용
			fin >> find_room_num;
			fin >> roomservice_cost;

			int idx = room_to_i(find_room_num);

			log << roomTypes[idx];
			log << (Room&)*rooms[idx] << " called room service($" << roomservice_cost << ")" << endl;

			rooms[idx]->roomService(roomservice_cost);
			break;
		}

		case ('q'): {				//c[0]==q일 때, 호텔 영업 종료
			//전체 수익 출력
			log << "Hotel closed." << endl;
			log << "Total income is $" << totalIncome << "." << endl;
			break;
		}
		default:
			cout << "----------error-------------" << endl;
		}
	}

	log.close();
}