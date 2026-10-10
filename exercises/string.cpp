#include <iostream>
#include <string>
using namespace std;


int main(){
    
    
     int arr[3]={1,2,3};
     int* ptr=arr;

     cout<<arr[2]<<*(ptr+1)<<endl;//ptr accessing is not working 
    cout<<arr[2]<<endl;
  

     char s1[]="apple";//does not need to provide the size of the array 
    // // simple string functions
     strcpy(s1,"frog");
     char copy[10];//the complier declares the two strings length different due to how the memory is being used.
     
    strcpy(copy,"banana");//the complier declares the two strings length different due to how the memory is being used.

    //  //string library needs to be included to use string types 

      string s2;
      s2="banana";
      s2+=" apple";//string concatenation 
     cout<<s2;









}