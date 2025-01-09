#include <iostream>
#include "Player.h"

Player::Player(const char* name)
	: Entity()
{
	std::cout << "Player() called\n";

	// ���� �Ҵ� �� ����.
	size_t length = strlen(name);

	// ���� �Ҵ�.
	this->name = new char[length + 1];

	// ���ڿ� ����.
	strcpy_s(this->name, length + 1, name);
}

Player::~Player()
{
	std::cout << "~Player() called\n";


	// �޸� ����.
	// false -> 0. �������� true.
	// if (name)
	if (name != nullptr)
	{
		delete[] name;
	}
}
