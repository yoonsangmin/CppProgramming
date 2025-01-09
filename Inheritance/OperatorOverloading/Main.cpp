#include <iostream>
#include "Vector2.h"

// << 연산자 오버로딩.
// 오버 엔지니어링.
// os - 출력 스트림
//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "(" << vector.GetX() << "," << vector.GetY() << ")\n";
//	return os;
//}

int main()
{
	//Vector2 position(4.0f, 4.0f);
	//Vector2 speed(0.5f, 0.5f);

	////Vector2 result = position.Multiply(speed);
	////Vector2 result = position * speed;
	//Vector2 result = position.operator*(speed);

	//std::cout << position << "\n";
	//std::cout << speed << "\n";
	//std::cout << result << "\n";

	// 뺄셈
	//Vector2 position1 = Vector2(4.0f, 3.0f);
	//Vector2 position2 = Vector2(2.0f, 1.0f);
	//Vector2 direction = position1 - position2;
	//std::cout << direction << "\n";

	// 비교 연산자
	//Vector2 position1 = Vector2(3.0f, 1.0f);
	//Vector2 position2 = Vector2(3.0f, 1.0f);
	//Vector2 position3 = Vector2(5.0f, 10.0f);

	//if (position1 == position2)
	//{
	//	std::cout << "position1과 position2는 같다.\n";
	//}
	//else
	//{
	//	std::cout << "position1과 position2는 다르다.\n";
	//}

	//if (position2 != position3)
	//{
	//	std::cout << "position2와 position3은 다르다.\n";
	//}
	//else
	//{
	//	std::cout << "position2와 position3은 같다.\n";
	//}

	// += 연산자
	Vector2 position = Vector2(4.0f, 3.0f);
	Vector2 direction = Vector2(1.0f, 1.0f);
	position += direction;
	std::cout << position << "\n";

	std::cin.get();
}