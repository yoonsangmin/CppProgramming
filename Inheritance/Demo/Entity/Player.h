#pragma once

#include "Entity.h"

// Entity Ŭ������ �θ�� ����.
class Player : public Entity
{
public:
	Player(const char* name);
	~Player();

private:
	char* name;
};