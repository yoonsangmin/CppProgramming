#include "DonationAccount.h"
#include <iostream>

DonationAccount::DonationAccount(int id, const char* name, int donatedAmount, int balance, bool isLoad)
    : Account(id, name, balance * 0.99), donatedAmount(balance * 0.01)
{
    // 로드 중인 계좌
    if (isLoad)
    {
        this->donatedAmount = donatedAmount;
        this->balance = balance;
    }
    
	type = Type::Donation;
}

bool DonationAccount::Deposit(int amount)
{
	if (amount <= 0)
	{
		return false;
	}

	int value = amount / 100;
	donatedAmount += value;
	balance += amount - value;
	return true;
}

void DonationAccount::Print() const
{
	std::cout << "계좌 유형  : 기부 계좌\n";
	std::cout << "고객 ID    : " << id << "\n";
	std::cout << "고객 이름  : " << name << "\n";
	std::cout << "잔액       : " << balance << "\n";
	std::cout << "기부액      : " << donatedAmount << "\n\n";
}

int DonationAccount::GetDonatedAmount() const
{
    return donatedAmount;
}
