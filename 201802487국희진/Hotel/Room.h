/*201802487 ��ǻ�Ͱ��к� ������*/

#ifndef ROOM_H
#define ROOM_H

enum class State { EMPTY, OCCUPIED, PREPARING };

enum class RoomType { STANDARD, SUITE, ROYAL };

class Room {
	string name;						//����� �̸�
	int roomNumber;						//����� �� �ѹ�
	int remainTime;						//���� �ð�(Preparing�� ���� ����)
protected:
	double fee;							//ȣ�� RoomType�� �̿� ���
	int people_num;						//�����ϴ� ��� ��
	int addFeePerPerson;				//�߰��ο��� �ݾ�
	int breakfastNo = 0;				//������ ���� �ο�
	static const int breakfastFee = 30;	//���� �ݾ��� 30�޷��� ����
	double serviceCost = 0;				//�ش� ���� �����ؾ��� ��ü �ݾ�
	State state = State::EMPTY;			//���� �ʱ� ���´� Empty
public:
	virtual ~Room() { }
	Room(int rn) {						//rn�� room number��.
		//������ �ʱ�ȭ���ش�.
		name = "";
		roomNumber = rn;
		remainTime = 0;
		fee = 0;
		people_num = 0;
	}
	virtual double calculate()const = 0;	//�����Լ�, RoomType���� ������ �κ�
	void checkin(string name, int people_num, int breakfastNo = 0);		//�̸�, �� �ο�, ���� �ο��� �Ű������� ����
	void checkout();
	virtual void roomService(int rs) {};
	void prepare();
	string getName()const {		//�̸� ��ȯ
		return name;
	}
	int getRoomNum()const {		//��ѹ� ��ȯ
		return roomNumber;
	}
	State getState()const {		//state ��ȯ
		return state;
	}
	void setState(State state) {	//state ����
		this->state = state;
	}
	double getServiceCost()const {	//serviceCost:�ش� �� �̿��� ��ȯ
		return serviceCost;
	}
	friend ofstream& operator<<(ofstream& log, const Room& r);
};

#endif