#include <iostream>
#include <cstdarg>

int sum(int n,...){
    
    va_list list;
    va_start(list,n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=va_arg(list,int);
    }
    va_end(list);
    return sum;


};

int main(){
  std::cout<<sum(3,10,20,30)<<std::endl;
  return 0;
}