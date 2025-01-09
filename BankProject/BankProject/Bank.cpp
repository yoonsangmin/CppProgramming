#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include <iostream>

Bank::Bank()
	: accountCount(0)
{
	memset(accounts, 0, sizeof(accounts) / sizeof(Account*));
}

Bank::~Bank()
{
	for (int ix = 0; ix < accountCount; ++ix)
	{
		if (accounts[ix] != nullptr)
		{
			delete accounts[ix];
		}
	}
}

void Bank::PrintMenu() const
{
	// 메뉴 목록 출력
	std::cout << "=== 원하시는 작업을 선택해주십시오. ===\n\n";

	std::cout << "1. 계좌 계설\n";
	std::cout << "2. 입금\n";
	std::cout << "3. 출금\n";
	std::cout << "4. 전체 고객 잔액 조회\n";
	std::cout << "q. 종료\n";
	std::cout << ">> ";
}

void Bank::ClearScreen() const
{
	system("cls");
}

bool Bank::CreateAccount(int id, const char* name, Type type, int money, int donatedAmount, bool isLoad)
{
	if (accountCount < 100)
	{
		// 계좌 생성
		switch (type)
		{
        case Type::Default:
			accounts[accountCount] = new Account(id, name, money);
			break;
		case Type::Credit:
			accounts[accountCount] = new CreditAccount(id, name, money, isLoad);
			break;
		case Type::Donation:
			accounts[accountCount] = new DonationAccount(id, name, donatedAmount, money, isLoad);
			break;
		}
        ++accountCount;
		return true;
	}
	
    return false;
}

void Bank::CreateAccount()
{
	int type;
	int id;
	int index;
	char name[256];
	int money;

	// 오류 확인을 위한 임시 버퍼.
	char tempBuffer[100];

	ClearScreen();

	// 계좌 개설 가능한지 확인
	if (accountCount == sizeof(accounts) / sizeof(Account*))
	{
		std::cout << "계좌를 개설에 실패했습니다. 더 이상 계좌를 개설할 수 없습니다.\n";
		return;
	}

	std::cout << "=== 계좌를 개설합니다. ===\n\n";

	// 계좌 타입 정보
	while (true)
	{
		std::cout << "계좌를 상품을 선택해주세요.\n";
		std::cout << "1. 일반 계좌\n";
		std::cout << "2. 신용 계좌\n";
		std::cout << "3. 기부 계좌\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;

		if (type = atoi(tempBuffer))
		{
			// 계좌 타입 유효성 체크
			if (type >= 1 && type <= 3)
			{
				break;
			}

			std::cout << "계좌 타입은 1부터 3까지 숫자만 입력해야 합니다.\n\n";
			continue;
		}

		std::cout << "계좌 타입은 숫자만 입력해야 합니다.\n\n";
	}

	// 계좌 번호
	while (true)
	{
		std::cout << "\n계좌 번호를 입력해주세요.\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;
		
		if (id = atoi(tempBuffer))
		{
			// 계좌 번호 유효성 체크
			index = FindAccountIndex(id);
			if (index == -1)
			{
				break;
			}

			std::cout << "이미 존재하는 계좌 번호입니다.\n";
			continue;
		}

		std::cout << "계좌 번호는 숫자만 입력해야 합니다.\n";
	}

	// 이름
	std::cout << "\n이름을 입력해주세요.\n";
	std::cout << ">> ";
	std::cin >> name;

	// 입금 금액
	while (true)
	{
		std::cout << "\n입금할 금액을 입력해주세요.\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;

		// 금액 유효성 체크
		if (money = atoi(tempBuffer))
		{
			if (money >= 0)
			{
				break;
			}

			std::cout << "불가능한 금액 입니다.\n";
			continue;
		}

		std::cout << "금액은 숫자만 입력 가능합니다.\n";
	}

	// 결과 출력 전에 화면 지우기
	ClearScreen();

	if (CreateAccount(id, name, static_cast<Type>(type), money))
	{
        Save(accountCount - 1);
		std::cout << "계좌가 개설되었습니다.\n\n";
	}
	else
	{
		std::cout << "계좌를 개설에 실패했습니다. 더 이상 계좌를 개설할 수 없습니다.\n\n";
	}
}

void Bank::Deposit() const
{
	int id;
	int index;
	int money;

	// 오류 확인을 위한 임시 버퍼.
	char tempBuffer[100];

	ClearScreen();

	if (accountCount == 0)
	{
		std::cout << "은행에 계설된 계좌가 없습니다.\n\n";
		return;
	}

	std::cout << "=== 계좌에서 현금을 입금합니다. ===\n\n";

	// 계좌 번호
	while (true)
	{
		std::cout << "\n계좌 번호를 입력해주세요.\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;

		if (id = atoi(tempBuffer))
		{
			// 계좌 번호 유효성 체크
			index = FindAccountIndex(id);
			if (index != -1)
			{
				break;
			}

			std::cout << "존재하지 않는 계좌입니다.\n";
			continue;
		}

		std::cout << "계좌 번호는 숫자만 입력해야 합니다.\n";
	}

	// 입금 금액
	while (true)
	{
		std::cout << "\n입금할 금액을 입력해주세요.\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;

		// 금액 유효성 체크
		if (money = atoi(tempBuffer))
		{
			if (money >= 0)
			{
				// 입금
				if (accounts[index]->Deposit(money))
				{
					break;
				}
			}
			
			std::cout << "불가능한 금액 입니다.\n";
			continue;
		}

		std::cout << "금액은 숫자만 입력 가능합니다.\n";
	}

	// 결과 출력 전에 화면 지우기
	ClearScreen();

    Save(index);
	std::cout << "입금이 완료되었습니다. 잔액은 " << accounts[index]->GetBalance() << "원 입니다.\n\n";
}

void Bank::Withdraw() const
{
	int id;
	int index;
	int balance;
	int money;

	// 오류 확인을 위한 임시 버퍼.
	char tempBuffer[100];

	ClearScreen();

	if (accountCount == 0)
	{
		std::cout << "은행에 계설된 계좌가 없습니다.\n\n";
		return;
	}

	std::cout << "=== 계좌에서 현금을 출금합니다. ===\n\n";

	// 계좌 번호
	while (true)
	{
		std::cout << "\n계좌 번호를 입력해주세요.\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;

		if (id = atoi(tempBuffer))
		{
			// 계좌 번호 유효성 체크
			index = FindAccountIndex(id);
			if (index != -1)
			{
				break;
			}

			std::cout << "존재하지 않는 계좌입니다.\n";
			continue;
		}

		std::cout << "계좌 번호는 숫자만 입력해야 합니다.\n";
	}

	balance = accounts[index]->GetBalance();
	if (balance == 0)
	{
		ClearScreen();
		std::cout << "출금 가능한 금액이 없습니다.\n\n";
		return;
	}

	std::cout << "\n현재 계좌의 잔액은 " << balance << "원 입니다.";

	// 출금 금액
	while (true)
	{
		std::cout << "\n출금할 금액을 입력해주세요.\n";
		std::cout << ">> ";
		std::cin >> tempBuffer;

		// 금액 유효성 체크
		if (money = atoi(tempBuffer))
		{
			if (money <= balance)
			{
				// 출금
				if (accounts[index]->Withdraw(money))
				{
					break;
				}

				std::cout << "불가능한 금액입니다.\n";
				continue;
			}

			std::cout << "잔액이 부족합니다. 계좌의 잔액은 "<< balance << "원 입니다.\n";
			continue;
		}

		std::cout << "금액은 숫자만 입력 가능합니다.\n";
	}

	// 결과 출력 전에 화면 지우기
	ClearScreen();

    Save(index);
	std::cout << "출금이 완료되었습니다.\n\n";
}

void Bank::Inquire() const
{
	ClearScreen();

	if (accountCount == 0)
	{
		std::cout << "은행에 계설된 계좌가 없습니다.\n\n";
		return;
	}

	std::cout << "=== 전체 고객 조회입니다. ===\n\n";
	
	//전체 고객 잔액 조회
	for (int ix = 0; ix < accountCount; ++ix)
	{
		accounts[ix]->Print();
	}

	std::cout << "\n이상입니다.\n";
	std::cout << "엔터키를 누르세요...\n";
	std::cin.ignore();
	std::cin.get();

	ClearScreen();
}

int Bank::FindAccountIndex(int id) const
{
	for (int ix = 0; ix < accountCount; ++ix)
	{
		if (accounts[ix]->GetID() == id)
		{
			return ix;
		}
	}

	return -1;
}

void Bank::RunATM()
{
	Load();

	ClearScreen();
	std::cout << "안녕하세요. 은행 계좌 관리 프로그램입니다.\n\n";

	char task;

	while (true)
	{
		PrintMenu();

		std::cin >> task;

		switch (task)
		{
		case '1':
			CreateAccount();
			break;
		case '2':
			Deposit();
			break;
		case '3':
			Withdraw();
			break;
		case '4':
			Inquire();
			break;
		case 'q':
		case 'Q':
			std::cout << "은행 계좌 관리 프로그램을 종료합니다.\n";
            SaveAll();
			return;
		default:
			ClearScreen();
            std::cout << "잘못된 입력입니다.\n\n";
			continue;
		}
	}
}

void Bank::Load()
{
    std::cout << "은행 정보를 로드합니다...\n";

    FILE* file = nullptr;
    fopen_s(&file, "BankDB.bin", "rb");
    if (file == nullptr)
    {
        std::cout << "저장된 정보가 없습니다.\n";
        return;
    }
    
    int id;
    Type type;
    int balance;
    int donatedAmount;
    char name[256];

    //while (fscanf_s(file, "%d %d %255s %d", &id, &type, name, (unsigned int)sizeof(name), &balance) == 4) {
    //    CreateAccount(id, name, type, balance);
    //}

    // 순서 매우 중요!!!
	while (fread(&id, sizeof(id), 1, file) == 1) {
        fread(&type, sizeof(type), 1, file);
        fread(&balance, sizeof(balance), 1, file);
        fread(&donatedAmount, sizeof(donatedAmount), 1, file);
        fread(name, sizeof(name), 1, file);
		CreateAccount(id, name, type, balance, donatedAmount, true);
	}
    
    fclose(file);
}

void Bank::Save(int index) const
{
    FILE* file = nullptr;
    fopen_s(&file, "BankDB.bin", "r+b");
    if (file == nullptr)
    {
        std::cout << "저장에 실패했습니다.\n";
        return;
    }

    Account* account = accounts[index];
    int id = account->GetID();
    Type type = account->GetType();
    int balance = account->GetBalance();
    int donatedAmount = type == Type::Donation ? static_cast<DonationAccount*>(account)->GetDonatedAmount() : 0;
    char name[256] = { 0 };
    strncpy_s(name, account->GetName(), 256);
    
    size_t tupleSize = sizeof(id) + sizeof(type) + sizeof(balance) + sizeof(donatedAmount) + sizeof(name);
    // 인덱스 위치로 이동
    fseek(file, tupleSize * index, SEEK_SET);
    
    // 순서 매우 중요!!!
    fwrite(&id, sizeof(id), 1, file);
    fwrite(&type, sizeof(type), 1, file);
    fwrite(&balance, sizeof(balance), 1, file);
    fwrite(&donatedAmount, sizeof(donatedAmount), 1, file);
    fwrite(name, sizeof(name), 1, file);

    fclose(file);
}

void Bank::SaveAll()
{
    std::cout << "은행 정보를 저장합니다...\n";

    FILE* file = nullptr;
    fopen_s(&file, "BankDB.bin", "wb");
    if (file == nullptr)
    {
        std::cout << "저장에 실패했습니다.\n";
        return;
    }

    for (int ix = 0; ix < accountCount; ++ix)
    {
        Account* account = accounts[ix];
        int id = account->GetID();
        Type type = account->GetType();
        int balance = account->GetBalance();
        int donatedAmount = type == Type::Donation ? static_cast<DonationAccount*>(account)->GetDonatedAmount() : 0;
        char name[256] = { 0 };
        strncpy_s(name, account->GetName(), 256);

        // fprintf(file, "%d %d %s %d\n", id, type, name, balance);

        // 순서 매우 중요!!!
        fwrite(&id, sizeof(id), 1, file);
        fwrite(&type, sizeof(type), 1, file);
        fwrite(&balance, sizeof(balance), 1, file);
        fwrite(&donatedAmount, sizeof(donatedAmount), 1, file);
        fwrite(name, sizeof(name), 1, file);
    }

    fclose(file);
}
