#pragma once

class Account;
class Bank
{
public:
	Bank();
	~Bank();

	// 선택 메뉴 출력.
	void PrintMenu() const;
	void ClearScreen() const;

	// 계좌 관련 기능
    bool CreateAccount(int id, const char* name, enum class Type type, int money, int donatedAmount = 0, bool isLoad = false);
	void CreateAccount();
	void Deposit() const;
	void Withdraw() const;
	void Inquire() const;

    int FindAccountIndex(int id) const;

	void RunATM();

	// 로드/세이브
    void Load();
    void Save(int index) const;
    void SaveAll();

private:
	int accountCount;
	Account* accounts[100] = { };
};