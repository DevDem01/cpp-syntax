#include "AdminUser.h"
#include <iostream>



AdminUser::AdminUser(string name,int id):User(name,id){

}
void AdminUser::changeSecurityLevel(RegularUser& user, int level){
    user.setSecurityLevel(level);
}
void AdminUser::readFile(const string& content)const{
        User::readFile(content);
}
void AdminUser::writeFile( string& original,const string& changed){
    User::writeFile(original,changed);
}