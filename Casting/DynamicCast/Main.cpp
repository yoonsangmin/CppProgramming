#include <iostream>

// Ÿ�� ������ ���� ��ũ��.
#define RTTI(name) \
	public:			\
		virtual const char* ClassName() const { return #name; }

class Actor
{
	RTTI(Actor)

public:
	// ���� �Լ�(Virtual Function).
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
	// ��ü ����
	Actor* actor = new Actor();
	Player* player = new Player();

	// �� ĳ����(Up-Casting).
	//Actor* actorPoint = reinterpret_cast<Actor*>(player);
	//Actor* actorPoint = (Actor*)player;
	Actor* actorPoint = player;

	// �� �� - �������� �����ؾ� �� - virtual
	//Player* playerPointer = dynamic_cast<Player*>(actorPoint);
	
	// OK.
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok.
	// dynamic cast
	Player* player2 = dynamic_cast<Player*>(actor);
	// ���� ó��.
	//if (Player* player2 = dynamic_cast<Player*>(actor))
	if (player2 != nullptr)
	{
		// �Լ� ȣ��.
		player2->PrintValue();
	}
	else
	{
		std::cout << "����ȯ ����\n";
	}

	// typeid.
	//const type_info& info = typeid(actorPoint);
	//std::cout << "Ÿ�� �̸�: " << info.name() << "\n";

	std::cout << "Actor Ÿ��: " << actor->ClassName() << "\n";
	std::cout << "Player Ÿ��: " << player->ClassName() << "\n";
	std::cout << "ActorPoint Ÿ��: " << actorPoint->ClassName() << "\n";

	// Ÿ�� ��.
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "Ÿ�� ����\n";
	}
	else
	{
		std::cout << "Ÿ�� �ٸ�.\n";
	}
}