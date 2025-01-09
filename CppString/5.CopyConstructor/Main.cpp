#include <iostream>

class Player
{
public:
	Player()
		: x(0), y(0)
	{
		// ���ڿ� ���� ���ϱ�.
		size_t length = strlen("Player") + 1;

		// ���� Ȯ��.
		name = new char[length];

		// ���ڿ� ����.
		strcpy_s(name, length, "Player");
	}

	// Player() = delete;

	Player(const char* name, int x, int y)
		: x(x), y(y)
	{
		size_t length = strlen(name) + 1;

		// ���� Ȯ��.
		this->name = new char[length];

		// ���ڿ� ����.
		strcpy_s(this->name, length, name);
	}

	// ���� ������.
	// C++ value category
	// lvalue/rvalue
	// int a = 10;
	// int number = a;
	// int& refNumber = a;
	// �ӽ� ������ �ּҸ� ���� �� ����
	// r value Reference - && �� �� �����
	Player(const Player& other)
	{
		std::cout << "Player(const Player& other) called\n";

		x = other.x;
		y = other.y;

		size_t length = strlen(other.name) + 1;

		// ���� Ȯ��.
		this->name = new char[length];

		// ���ڿ� ����.
		strcpy_s(this->name, length, other.name);
	}

	// �Ҹ���.
	~Player()
	{
		// �� �޸� ����.
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