#pragma once


// 클래스 선언.
// 미들웨어 (운영체제 위에서 동작하는 프로그램).
class Entity
{
public:
	Entity();
	~Entity();

	void Move(int xAmount, int yAmount);

protected:
	int x;
	int y;
};