#pragma once
#include <iostream> 

// Ŭ���� ����.
// �̵���� (�ü�� ������ �����ϴ� ���α׷�).
class IEntity
{
public:
	//Entity();
	//virtual ~Entity();

	//void Move(int xAmount, int yAmount);
	//
	// ���� �Լ�.
	/*virtual const char* GetName() { return "Entity"; }*/

	// ���� ���� �Լ�
	// ����: �� �Լ��� �ʼ������� �����ϵ��� ������
	virtual const char* GetName() = 0;

//protected:
	//int x;
	//int y;
};