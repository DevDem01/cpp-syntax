#ifndef AdminUser_H
#define AdminUser_H
#include <string>
#include "RegularUser.h"
using std::string;
class AdminUser:public User{
    public:
    AdminUser(string name,int id);
    void changeSecurityLevel(RegularUser& user,int level);
    void readFile(const string& content )const override;
    void writeFile(string& original,const string& changed)override;

};
#endif