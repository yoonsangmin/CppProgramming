#pragma once

#include "Entity.h"

// Entity 클래스를 부모로 지정.
class Player : public Entity
{
public:
	Player(const char* name);
	~Player();

private:
	char* name;
};