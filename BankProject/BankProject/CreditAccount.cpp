#include "CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(int id, const char* name, int balance, bool isLoad)
    : Account(id, name, 0)
{
    this->balance = balance;

    // 신설 중인 계좌
    if (!isLoad)
    {
        balance += balance / 100;
    }

	type = Type::Credit;
}

bool CreditAccount::Deposit(int amount)
{
	if (amount <= 0)
	{
		return false;
	}

	balance += amount;
	balance += balance / 100;
	return true;
}

void CreditAccount::Print() const
{
	std::cout << "계좌 유형  : 신용 계좌\n";
	std::cout << "고객 ID    : " << id << "\n";
	std::cout << "고객 이름  : " << name << "\n";
	std::cout << "잔액       : " << balance << "\n\n";
}
