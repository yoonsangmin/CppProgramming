#include "Entity.h"
#include "Player.h"
#include <iostream>

int main()
{
	// Entity ��ü ����.
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player ��ü ����.
	IEntity* player = new Player("RonnieJ");
	std::cout << player->GetName() << "\n";

	// �޸� ����.
	//delete entity;
	delete player;

	std::cin.get();
}