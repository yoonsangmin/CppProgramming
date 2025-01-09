#pragma once

#include "Entity.h"
#include "IMovable.h"
#include <iostream> 

// Entity 클래스를 부모로 지정.
class Player : public IEntity, public IMovable // 다중 상속, 여러 부모를 가짐.
{
public:
	Player(const char* name);
	~Player();

	// 가상 함수(virtual 키워드가 추가된 함수).
	virtual const char* GetName() override { return name; }

	virtual void Move(int xAmount, int yAmount) override
	{

	}

private:
	char* name;
};