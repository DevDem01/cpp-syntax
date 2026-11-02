#include <iostream>

int main()
{
    int a = 20;
    int b = 30;
    []()
    { std::cout << "Hello" << std::endl; }();
    [=]()
    { std::cout << a << " " << b << std::endl; }();
    [&a, b]()
    {a=30; std::cout<<a<<" "<<b<<std::endl; }();
}