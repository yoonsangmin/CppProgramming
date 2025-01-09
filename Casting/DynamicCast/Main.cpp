#include <iostream>

// 타입 정보를 위한 매크로.
#define RTTI(name) \
	public:			\
		virtual const char* ClassName() const { return #name; }

class Actor
{
	RTTI(Actor)

public:
	// 가상 함수(Virtual Function).
	virtual void PrintValue()
	{
		std::cout << "Value: " << a << "\n";
	}

protected:
	int a;
};

class Player : public Actor
{
	RTTI(Player)
};

int main()
{
	// 객체 생성
	Actor* actor = new Actor();
	Player* player = new Player();

	// 업 캐스팅(Up-Casting).
	//Actor* actorPoint = reinterpret_cast<Actor*>(player);
	//Actor* actorPoint = (Actor*)player;
	Actor* actorPoint = player;

	// 안 됨 - 다형성을 지원해야 함 - virtual
	//Player* playerPointer = dynamic_cast<Player*>(actorPoint);
	
	// OK.
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok.
	// dynamic cast
	Player* player2 = dynamic_cast<Player*>(actor);
	// 예외 처리.
	//if (Player* player2 = dynamic_cast<Player*>(actor))
	if (player2 != nullptr)
	{
		// 함수 호출.
		player2->PrintValue();
	}
	else
	{
		std::cout << "형변환 실패\n";
	}

	// typeid.
	//const type_info& info = typeid(actorPoint);
	//std::cout << "타입 이름: " << info.name() << "\n";

	std::cout << "Actor 타입: " << actor->ClassName() << "\n";
	std::cout << "Player 타입: " << player->ClassName() << "\n";
	std::cout << "ActorPoint 타입: " << actorPoint->ClassName() << "\n";

	// 타입 비교.
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "타입 동일\n";
	}
	else
	{
		std::cout << "타입 다름.\n";
	}
}