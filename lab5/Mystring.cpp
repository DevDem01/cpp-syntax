#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    private:
    char* data;
    int length;

    public:
    MyString(){
    this->data=new char[1]{'\0'};
    this->length=0;

};
    MyString(const char* str){
        this->length=strlen(str);
        this->data= new char[this.length+1];
        strcpy(this->data,str);

    }
    int size()const{
       return this->length;

    } ;
     ostream & operator<<(ostream &cout,const MyString& s){
        cout<<s.data;
        return cout;
     }
    // const char getchar(int index){
    //       for(int i=0;i<this->data.strlen();i++){

    //       }

    // };

}

int main(){
  MyString arr("World");
  cout<< arr<<endl;
}