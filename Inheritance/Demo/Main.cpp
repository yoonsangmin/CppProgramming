#include "Entity.h"
#include "Player.h"
#include <iostream>

int main()
{
	// Entity 객체 생성.
	Entity* entity = new Entity();

	// Player 객체 생성.
	Player* player = new Player("Ronnie");

	// 다형성.
	Entity* entity2 = player;

	// World -> Level(Scene) = Actor* level[].
	// class TestActor : public Actor { }
	// AddActor(Actor* actor);
	// TestActor* test = new TestActor(); AddActor(test);
	// 형변환 실패 시 nullptr.

	delete entity;
	delete player;

	std::cin.get();
}