#include "String.h"

String::String(const char* string)
{
    // ���� Ȯ��.
    // ���� ������.
    //length = string = nullptr ? 1 : (int)strlen(string);
    length = string == nullptr ? 1 : static_cast<int>(strlen(string));

    // ���� �Ҵ� �� ���ڿ� ����.
    data = new char[length + 1];
    if (string != nullptr)
    {
        strcpy_s(data, length + 1, string);
    }
}

String::String(const String& other)
{
    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);
}

String::~String()
{
    // �޸� ����.
    delete[] data;
}

String& String::operator=(const String& other)
{
    // ������ data ����. Ȯ���ϱ� ������ nullptr üũ �� �ص� ������
    delete[] data;

    length = other.length;
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);

    return *this;
}

String String::operator+(const String& other)
{
    int newLength = length + other.length;
    char* newData = new char[newLength + 1];
    strcpy_s(newData, length + 1, data);
    strcat_s(newData, newLength + 1, other.data);

    String newString(newData);
    delete[] newData;

    return newString;
}

String& String::operator+=(const String& other)
{
    int newLength = length + other.length;
    char* newData = new char[newLength + 1];
    strcpy_s(newData, length + 1, data);
    delete[] data;

    strcat_s(newData, newLength + 1, other.data);
    data = newData;

    return *this;
}

bool String::operator==(const String& other)
{
    // ���ڿ� �� C���̺귯�� �Լ�.
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other)
{
    return strcmp(data, other.data) != 0;
    //return !(*this == other);
}

const int String::Length() const
{
    return length;
}

const char* String::Data() const
{
    return data;
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
    os << string.data;
    return os;
}
