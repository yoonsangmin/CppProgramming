#include <iostream>

class Player
{
public:
	Player()
		: x(0), y(0)
	{
		// 문자열 길이 구하기.
		size_t length = strlen("Player") + 1;

		// 공간 확보.
		name = new char[length];

		// 문자열 복사.
		strcpy_s(name, length, "Player");
	}

	// Player() = delete;

	Player(const char* name, int x, int y)
		: x(x), y(y)
	{
		size_t length = strlen(name) + 1;

		// 공간 확보.
		this->name = new char[length];

		// 문자열 복사.
		strcpy_s(this->name, length, name);
	}

	// 복사 생성자.
	// C++ value category
	// lvalue/rvalue
	// int a = 10;
	// int number = a;
	// int& refNumber = a;
	// 임시 값에는 주소를 구할 수 없음
	// r value Reference - && 두 개 사용함
	Player(const Player& other)
	{
		std::cout << "Player(const Player& other) called\n";

		x = other.x;
		y = other.y;

		size_t length = strlen(other.name) + 1;

		// 공간 확보.
		this->name = new char[length];

		// 문자열 복사.
		strcpy_s(this->name, length, other.name);
	}

	// 소멸자.
	~Player()
	{
		// 힙 메모리 해제.
		delete[] name;
	}

	void Print()
	{
		std::cout << "name: " << name << " x: " << x << ", y: " << y << "\n";
	}

private:
	int x;
	int y;
	char* name;
};

int main()
{
	Player player1 = Player("Ronnie", 0, 0);
	Player player2 = Player(player1);

	player1.Print();
	player2.Print();

	std::cin.get();
}