#include "Entity.h"
#include "Player.h"
#include <iostream>

int main()
{
	// Entity ��ü ����.
	Entity* entity = new Entity();

	// Player ��ü ����.
	Player* player = new Player("Ronnie");

	// ������.
	Entity* entity2 = player;

	// World -> Level(Scene) = Actor* level[].
	// class TestActor : public Actor { }
	// AddActor(Actor* actor);
	// TestActor* test = new TestActor(); AddActor(test);
	// ����ȯ ���� �� nullptr.

	delete entity;
	delete player;

	std::cin.get();
}