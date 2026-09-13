#include <iostream>
using namespace std;
#include <cmath>


int main(){
    int secret=rand()%11+1;  
    int answer;
    cout<<"Please enter a guess: ";
    cin>>answer;
    while(secret!=answer){
        cout<<"Guess:"<<" "<<answer<<endl;
        if(answer>secret){
            cout<<"Too big\n";
            cout<<"Enter another guess: ";
            cin>>answer;
        }
        else {
            cout<<" Too small\n";  
            cout<<"Enter another guess: ";
            cin>>answer;
        }
       }
    cout<<"Correct!";
    return 0;
    
   


}
