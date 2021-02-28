/*201802487 ��ǻ�Ͱ��к� ������*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Hotel.h"
#include "Room.h"
#include "Standard.h"
#include "Suite.h"
#include "Royal.h"


//����� ���� ������. log<<RoomType ����
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


//Hotel ������
Hotel::Hotel(ifstream& setting) {
	string line;
	string type;		//RoomType�� �Է¹��� ����
	int rn;				//Room Number�� �Է¹��� ����

	getline(setting, line);		//�ð� �Է¹���
	time = stoi(line);

	getline(setting, line);		//ȣ�� �� ���� �Է¹���
	size = stoi(line);

	rooms = new Room * [size];			//��ü �迭 ����
	roomTypes = new RoomType[size];

	int i = 0;
	while (setting) {					//setting.txt�� �д´�.
		setting >> type >> rn;			//type�� room number�� �д´�.

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



/*�ش� ��ѹ��� ���� �ִ� rooms�� �ε����� ��ȯ�ϴ� �Լ�*/
int Hotel::room_to_i(const int rn) {		//rn: Room Number
	int index;
	for (index = 0; index < size; index++) {
		if (rooms[index]->getRoomNum() == rn) {
			return index;
		}
	}
	return -1;
}



/*���� fin�� ���� �д� �Լ�*/
void Hotel::open(ifstream& fin) {
	ofstream log("log.txt");						//���ڸ� �Է¹��� log.txt�� ����.
	log << "Time: " << time << ":00" << endl;
	log << "Hotel opened." << endl;
	string c;
	while (fin) {
		if (fin.eof()) break;						//���� ������ ���̶�� �ݺ����� �����.

		fin >> c;									//���ڿ� c�� �д´�.

		switch (c[0])
		{
		case ('i'): {			//c[0]==i�� ��
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

			case ('s'): {			//is[0]==s�� ��, Standard�� checkin
				int idx = -1;			//�ε����� ������ ����
				int other_num;		//'�� �� �ο�'�� ������ ����
				for (int k = 0; k < size; k++) {
					//Standard�̰� ����ִ� ���� ã�´�.
					if (roomTypes[k] == RoomType::STANDARD && rooms[k]->getState() == State::EMPTY) {
						idx = k;		//ã�� �ε��� ���� idx�� �����Ͽ� ����
						break;
					}
					
				}
				if (idx == -1) {
					cout << "Standard Room not available" << endl;
					log << "Standard Room not available" << endl;
					break;
				}

				//checkin�Լ��� �̿��� �ʱ�ȭ
				rooms[idx]->checkin(name, people_num, breakfast_num);
				//State�� Occupied�� ����
				rooms[idx]->setState(State::OCCUPIED);
				other_num = people_num - 1;
				log << "Checked in to Standard Room ";
				log << (Room&)*rooms[idx] << endl;

				break;
			}

			case ('u'): {				//is[0]==u�� ��, Suite�� checkin
				//������ ���� ����
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

			case ('r'): {				//is[0]==r�� ��, Royal�� checkin
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

		case ('o'): {				//c[0]==o�� ��, check out ����
			int out_room_num;		//check-out�Ϸ��� ���� ��ѹ��� ����Ű�� ����
			fin >> out_room_num;

			int idx = room_to_i(out_room_num);		//�ش� ��ѹ��� ���� �ִ� ��ü�迭�� �ε����� ���Ѵ�.
			if (rooms[idx]->getState() != State::OCCUPIED) {
				cout << "check-out error: Room " << out_room_num << " is Empty" << endl;
				log << "check-out error: Room " << out_room_num << " is Empty" << endl;
				break;
			}

			//��ü �ݾ� = calculate���� ��ȯ�� �ݾ� + serviceCost�� ���Ѵ�.
			//getServiceCost�� ��ȯ�� serviceCost���� room service�� ���� �߰� �ݾ׵� ���� �ִ�. 
			int RoomTotalCost = rooms[idx]->calculate() + rooms[idx]->getServiceCost();

			log << roomTypes[idx];
			log << (Room&)*rooms[idx] << " checked out." << endl;
			log << "&" << RoomTotalCost << " added to the total income." << endl;

			rooms[idx]->checkout();		//rooms[idx]�� ���� checkout()����.
			totalIncome += RoomTotalCost;	//check-out���� ���� ��, ��ü ���Ϳ� �ش� Room ������ �����ش�.

			break;
		}
		case ('p'): {
			for (int k = 0; k < size; k++) {
				int RoomTotalCost = rooms[k]->calculate() + rooms[k]->getServiceCost();
				log << roomTypes[k];

				//���� Occupied ���¶��, ���ݱ��� �߻��� ����� �Բ� ������ش�.
				if (rooms[k]->getState() == State::OCCUPIED) {
					log << (Room&)*rooms[k] << " $" << RoomTotalCost << " expected" << endl;
				}
				else {
					log << (Room&)*rooms[k] << endl;
				}

			}

			break;
		}

		case ('a'): {		//c[0]==a�� ��, �� �ð� ���
			++time;
			if (time >= 24) {
				time = time - 24;		//0~23���� ���ư����� �Ѵ�.
			}

			//�ð� ���� ������ prepare()�� ����ǹǷ� 'a'�� ������ ���ÿ� prepare()�� �Բ� ����
			for (int k = 0; k < size; k++) {
				//���� Preparing���¶�� prepare()�� ����
				if (rooms[k]->getState() == State::PREPARING) {
					rooms[k]->prepare();
					break;
				}
			}

			log << endl;
			log << "Time: " << time << ":00" << endl;
			break;
		}

		case ('s'): {					//c[0]==s �� ��, Room service ����
			int find_room_num;			//ã�� ��ѹ�
			int roomservice_cost;		//room servie ���
			fin >> find_room_num;
			fin >> roomservice_cost;

			int idx = room_to_i(find_room_num);

			log << roomTypes[idx];
			log << (Room&)*rooms[idx] << " called room service($" << roomservice_cost << ")" << endl;

			rooms[idx]->roomService(roomservice_cost);
			break;
		}

		case ('q'): {				//c[0]==q�� ��, ȣ�� ���� ����
			//��ü ���� ���
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