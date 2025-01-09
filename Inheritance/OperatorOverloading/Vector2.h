#pragma once

#include <iostream>

// 2차원 벡터 클래스.
class Vector2
{
public:
	Vector2();
	Vector2(float x = 0.0f, float y = 0.0f);

	//// 더하기.
	//Vector2 Add(const Vector2& other);

	//// 곱하기.
	//Vector2 Multiply(const Vector2& other);

	// 연산자 오버로딩.
	// 특별한 함수.
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);
	Vector2& operator+=(const Vector2& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.GetX() << "," << vector.GetY() << ")\n";
		return os;
	}

	// Getter/Setter.
	float GetX() const;
	float GetY() const;

private:
	float x;
	float y;
};

