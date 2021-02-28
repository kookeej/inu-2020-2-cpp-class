/*201802487 컴퓨터공학부 국희진*/

#ifndef ROOM_H
#define ROOM_H

enum class State { EMPTY, OCCUPIED, PREPARING };

enum class RoomType { STANDARD, SUITE, ROYAL };

class Room {
	string name;						//사용자 이름
	int roomNumber;						//사용할 룸 넘버
	int remainTime;						//남은 시간(Preparing때 사용될 변수)
protected:
	double fee;							//호텔 RoomType별 이용 요금
	int people_num;						//입장하는 사람 수
	int addFeePerPerson;				//추가인원당 금액
	int breakfastNo = 0;				//조식을 먹을 인원
	static const int breakfastFee = 30;	//조식 금액은 30달러로 고정
	double serviceCost = 0;				//해당 방의 지불해야할 전체 금액
	State state = State::EMPTY;			//방의 초기 상태는 Empty
public:
	virtual ~Room() { }
	Room(int rn) {						//rn은 room number다.
		//변수를 초기화해준다.
		name = "";
		roomNumber = rn;
		remainTime = 0;
		fee = 0;
		people_num = 0;
	}
	virtual double calculate()const = 0;	//가상함수, RoomType별로 구현될 부분
	void checkin(string name, int people_num, int breakfastNo = 0);		//이름, 총 인원, 조식 인원을 매개변수로 받음
	void checkout();
	virtual void roomService(int rs) {};
	void prepare();
	string getName()const {		//이름 반환
		return name;
	}
	int getRoomNum()const {		//룸넘버 반환
		return roomNumber;
	}
	State getState()const {		//state 반환
		return state;
	}
	void setState(State state) {	//state 설정
		this->state = state;
	}
	double getServiceCost()const {	//serviceCost:해당 룸 이용요금 반환
		return serviceCost;
	}
	friend ofstream& operator<<(ofstream& log, const Room& r);
};

#endif