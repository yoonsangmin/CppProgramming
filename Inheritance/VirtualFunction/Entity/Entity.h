#pragma once
#include <iostream> 

// 클래스 선언.
// 미들웨어 (운영체제 위에서 동작하는 프로그램).
class IEntity
{
public:
	//Entity();
	//virtual ~Entity();

	//void Move(int xAmount, int yAmount);
	//
	// 가상 함수.
	/*virtual const char* GetName() { return "Entity"; }*/

	// 순수 가상 함수
	// 목적: 이 함수를 필수적으로 구현하도록 강제함
	virtual const char* GetName() = 0;

//protected:
	//int x;
	//int y;
};