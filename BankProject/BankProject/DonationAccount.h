#pragma once
#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int donatedAmount, int balance, bool isLoad);

	virtual bool Deposit(int amount) override;

	virtual void Print() const override;

    int GetDonatedAmount() const; 

private:
	int donatedAmount;
};

