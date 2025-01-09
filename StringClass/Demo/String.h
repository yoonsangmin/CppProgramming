#pragma once

#include <iostream>

// ���� �����غ��� ���ڿ� Ŭ����.
// MFC - UI. cstring ó�� Ŭ���� �տ� C�� ���� �ٿ���
class String
{
public:
	// �Ϲ� ������.
	String(const char* string = nullptr);
	
	// ���� ������.
	String(const String& other);
	
	// �Ҹ���.
	~String();

	// ������ �����ε�.
	friend std::ostream& operator<<(std::ostream& os, const String& string);

	// ���� ������.
	String& operator=(const String& other);

	String operator+(const String& other);
	
	String& operator+=(const String& other);

	// �� ������.
	bool operator==(const String& other);
	bool operator!=(const String& other);

	// Getter.
	const int Length() const;
	const char* Data() const;

private:
	int length; // ���ڿ� ����.
	char* data; // ���ڿ� �����ϴ� ����(�����/�����̳�/Container).
};

