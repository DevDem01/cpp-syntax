#include <iostream>
#include "RegularUser.h"

RegularUser::RegularUser(string name, int id, int level) : User(name, id), securityLevel(level)
{
}

int RegularUser::getSecurityLevel() const
{
    return securityLevel;
};
void RegularUser::setSecurityLevel(int level)
{
    if (level >= 1 && level <= 2)
        securityLevel = level;
};

void RegularUser::readFile(const string &content) const
{
    User::readFile(content);
};
void RegularUser::writeFile(string &content,
                            const string &newContent)
{
    if (securityLevel == 2)
    {
        content = newContent;
    }
    else
    {
        cout << "Cannot modify the file" << endl;
    }
};