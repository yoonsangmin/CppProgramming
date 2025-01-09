#pragma once

enum class Type
{
    Default = 1,
    Credit,
    Donation,
};

class Account
{
public:
	Account() = delete;

	Account(int id, const char* name, int balance);
	Account(const Account& other);

	virtual ~Account();

	int GetBalance() const;

    Type GetType() const;

    int GetID() const;

	const char* GetName() const;

	virtual bool Deposit(int amount);

	bool Withdraw(int amount);

	virtual void Print() const;

protected:
	int id;
    Type type;
	char* name;
	int balance;
};
