#include <iostream>
#include <stdlib.h>
using namespace std;



int main(){
    int Choice;

    cout<<"Hello This is Rock Paper Scissors: \n";
    cout<<"Rock=0, Paper=1, Scissors=2 \n";
    cout<<"Please Enter a number: " ;
    cin>>Choice;
    int random=rand()%3;
    if (random==2 && Choice==0)
    {
        cout<<"YOU WIN!!";
    }
        else if (random==0 && Choice==1)
    {
        cout<<"YOU WIN!!";
    }
       else if (random==1 && Choice==2)
    {
        cout<<"YOU WIN!! :)";
    }
    else if(random==Choice)
    { 
        cout<<"Tie";
    }
    else
    {
      cout<<"You Lose :(";
    }


    
}