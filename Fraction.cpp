#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct fraction
{
    int numerator, denominator;
};

fraction operator+(fraction p1, fraction p2)
{
    return {p1.numerator * p2.denominator + p2.numerator * p1.denominator,
            p1.denominator * p2.denominator};
};
fraction operator-(fraction p1, fraction p2)
{
    return {p1.numerator * p2.denominator - p2.numerator * p1.denominator,
            p1.denominator * p2.denominator};
}
fraction operator*(fraction p1, fraction p2)
{
    return {p1.numerator * p2.numerator, p1.denominator * p2.denominator};
}
fraction operator/(fraction p1, fraction p2)
{
    return {p1.numerator * p2.denominator, p1.denominator * p2.numerator};
}

ostream &operator<<(ostream &stream, fraction c)
{
    stream << c.numerator << '/' << c.denominator;
    return stream;
}

int main()
{
    fraction a;
    fraction b;
    cout << "Enter values for The first fractions numerator and denominator\n";
    cout<<"Numerator: ";
    cin >> a.numerator;
    cout<<"Denominator: ";
    cin >> a.denominator;
    cout << "Enter values for The Second fractions numerator and denominator\n";
    cout<<"Numerator: ";
    cin >> b.numerator;
    cout<<"Denominator: ";
    cin >> b.denominator;
    cout << a << endl;
    cout << b << endl;

    cout << "Addition:" << a + b << endl;
    cout << "Subtraction:" << a - b << endl;
    cout << "Multiplication:" << a * b << endl;
    cout << "Divsion:" << a / b << endl;
}