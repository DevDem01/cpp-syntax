#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    void display() {
        cout << real << "+i" << img;
    }

    friend Complex operator+(Complex x, Complex y);

    friend ostream &operator<<(ostream &out, const Complex &c);
};

Complex operator+(Complex x, Complex y) {
    Complex temp;

    temp.real = x.real + y.real;
    temp.img = x.img + y.img;

    return temp;
};

ostream &operator<<(ostream &out, const Complex &c) {
    out << c.real << "+i" << c.img;
    return out;
};

int main() {
    char S[10]="Hello";
    cout<<S<<endl;
    Complex c1(5, 3), c2(10, 5), c3;

    c3 = c1 + c2;

    c3.display();

    cout << endl;

    cout << c1;

    return 0;
}