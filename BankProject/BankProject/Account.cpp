#include "Account.h"
#include <iostream>

Account::Account(int id, const char* name, int balance)
	: id(id), type(Type::Default), balance(balance)
{
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Account::Account(const Account& other)
{
	id = other.id;
	type = other.type;
	balance = other.balance;

	size_t length = strlen(other.name) + 1;
	name = new char[length];
	strcpy_s(name, length, other.name);
}

Account::~Account()
{
	delete[] name;
}

int Account::GetBalance() const
{
	return balance;
}

Type Account::GetType() const
{
    return type;
}

int Account::GetID() const
{
    return id;
}

const char* Account::GetName() const
{
	return name;
}

bool Account::Deposit(int amount)
{
	if (amount <= 0)
	{
		return false;
	}

	balance += amount;
	return true;
}

bool Account::Withdraw(int amount)
{
	if (balance < amount)
	{
		return false;
	}

	balance -= amount;
	return true;
}

void Account::Print() const
{
	std::cout << "계좌 유형  : 일반 계좌\n";
	std::cout << "고객 ID    : " << id << "\n";
	std::cout << "고객 이름  : " << name << "\n";
	std::cout << "잔액       : " << balance << "\n\n";
}
