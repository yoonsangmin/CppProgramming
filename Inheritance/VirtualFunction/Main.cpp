#include "Entity.h"
#include "Player.h"
#include <iostream>

int main()
{
	// Entity 按眉 积己.
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player 按眉 积己.
	IEntity* player = new Player("RonnieJ");
	std::cout << player->GetName() << "\n";

	// 皋葛府 秦力.
	//delete entity;
	delete player;

	std::cin.get();
}