#include <iostream>
#include "AdminUser.h"
#include "RegularUser.h"
#include "User.h"
using std::cout;
using std::endl;

// int main()
// {
//    string fileContent = "Original content";
// RegularUser alice("Alice", 1001, 1);
// RegularUser charlie("Charlie", 1002, 2);
// AdminUser bob("Bob", 2001);
// AdminUser diana("Diana", 2002);
// cout << "\n=== Alice ===" << endl;
// alice.readFile(fileContent);
// alice.writeFile(fileContent, "Edited by Alice"); // not allowed for security
// // level 1
// alice.readFile(fileContent);
// cout << "\n=== Charlie ===" << endl;
// charlie.readFile(fileContent);
// charlie.writeFile(fileContent, "Edited by Charlie"); // allowed for security
// // level 2
// charlie.readFile(fileContent);
// cout << "\n=== Bob ===" << endl;
// bob.readFile(fileContent);
// bob.writeFile(fileContent, "Edited by Bob"); // allowed for admin
// bob.readFile(fileContent);
// cout << "\n=== Diana ===" << endl;
// diana.readFile(fileContent);
// diana.writeFile(fileContent, "Edited by Diana"); // allowed for admin
// diana.readFile(fileContent);
// return 0;
// }

void testFileAccess(User *users[], int size,
                    string &fileContent)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nUser: "
             << users[i]->getUsername() << endl;
        users[i]->readFile(fileContent);
        users[i]->writeFile(
            fileContent,
            "Edited by " + users[i]->getUsername());
        users[i]->readFile(fileContent);
    }
}

int main()
{
    string fileContent = "Original content";
    RegularUser alice("Alice", 1001, 1);
    RegularUser charlie("Charlie", 1002, 2);
    AdminUser bob("Bob", 2001);
    AdminUser diana("Diana", 2002);
    User *users[] = {
        &alice, &charlie, &bob, &diana};
    int size = sizeof(users) / sizeof(users[0]);
    testFileAccess(users, size, fileContent);
    cout << "\n=== Security Level Change Test ===" << endl;

cout << "Alice's level before: "
     << alice.getSecurityLevel() << endl;

bob.changeSecurityLevel(alice, 2);

cout << "Alice's level after: "
     << alice.getSecurityLevel() << endl;

alice.writeFile(fileContent, "Edited by Alice");

alice.readFile(fileContent);
    return 0;
}
