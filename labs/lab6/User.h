#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class User
{
private:
  string username;
  int userID;

public:
  User(string name, int id);

  string getUsername() const;
  int getUserID() const;

  virtual void readFile(const string &content) const;
  virtual void writeFile(string &content, const string &newContent);
};

#endif
