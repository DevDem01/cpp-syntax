#ifndef REGULARUSER_H
#define REGULARUSER_H
using std::string;
#include "User.h"
#include <string>

class RegularUser : public User {
private:
    int securityLevel;

public:
    RegularUser(string name, int id, int level);

    int getSecurityLevel() const;
    void setSecurityLevel(int level);

    void readFile(const string& content) const override;
    void writeFile(string& content,
                   const string& newContent)override;
};

#endif