#include <iostream>

// Main.cpp -> 컴파일 -> Main.obj
// 링커(Linker) -> Library.lib
// exe 실행.

// 1차
// 선언만 하기
//class Math
//{
//public:
//    static int Add(int a, int b);
//    static int Substract(int a, int b);
//    static int Multiply(int a, int b);
//    static int Divide(int a, int b);
//};

// 2차.
#include <MyMath.h>

int main()
{
    std::cout << "Hello\n";

    std::cout << "10 + 20 = " << Math::Add(10,20) << "\n";
    std::cout << "10 - 20 = " << Math::Substract(10,20) << "\n";

    std::cin.get();
}