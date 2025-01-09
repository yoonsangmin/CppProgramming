#pragma once

#include "Entity.h"
#include "IMovable.h"
#include <iostream> 

// Entity Ŭ������ �θ�� ����.
class Player : public IEntity, public IMovable // ���� ���, ���� �θ� ����.
{
public:
	Player(const char* name);
	~Player();

	// ���� �Լ�(virtual Ű���尡 �߰��� �Լ�).
	virtual const char* GetName() override { return name; }

	virtual void Move(int xAmount, int yAmount) override
	{

	}

private:
	char* name;
};