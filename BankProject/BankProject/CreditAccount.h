#pragma once
#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount(int id, const char* name, int balance, bool isLoad);

	virtual bool Deposit(int amount) override;

	virtual void Print() const override;
};