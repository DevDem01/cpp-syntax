#include <iostream>
using namespace std;

class Complex
{
    public:
    int real;
    int img;
    Complex(int r=0,int i=0){
        real=r;
        img=i;
    }

    Complex operator+(Complex c){
        Complex temp;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }

};

int main()
{
    Complex C1(5,3);
    Complex C2(10,5);

    Complex C3=C1+C2;

     cout<<C3.real<<"+i"<<C3.img<<endl;

   


    

}