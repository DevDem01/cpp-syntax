#include <iostream>



int main(){
    int i;
    std::cout<<"Please enter a number:";
    std::cin>>i;
    for(;i<51;i++){
        if(i%15==0){
           std::cout<<"FizzBuzz\n";

        }
        else if(i%5==0){
            std::cout<<"Buzz\n";
        }
        else if(i%3==0){
            std::cout<<"Fizz\n";
        }
        else
        {
         std::cout<<i<<"\n";
        }
    }
    return 0;
}