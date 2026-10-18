#include <iostream>
#include "User.h"
#include <string>


User::User(string name, int id) : username(name), userID(id)
{
}

string User::getUsername() const
{
    return username;
}

int User::getUserID() const
{

    return userID;
}
void User::readFile(const string &content) const
{
    cout << content << endl;
}

void User::writeFile(string &content, const string &newContent)
{
    content = newContent;
}
