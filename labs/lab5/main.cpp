#include <iostream>
#include <cassert>
#include "Mystring.h"

int main() {
    MyString s("hello");
    assert(s.size() == 5);
    assert(s.getChar(1) == 'e');

    std::cout << "Initial string: ";
    s.print();
    std::cout << "Length: " << s.size() << std::endl;
    std::cout << "Character at index 1: "
              << s.getChar(1) << std::endl;

    s.setChar(0, 'H');
    std::cout << "After setChar: ";
    s.print();

    s.setString("Computer Science");
    std::cout << "After setString: ";
    s.print();
    std::cout << "New length: " << s.size() << std::endl;

    MyString copy = s;
    copy.setChar(0, 'c');
    assert(copy.getChar(0) == 'c');
    assert(s.getChar(0) == 'C');
    std::cout << "Copy: ";
    copy.print();
    std::cout << "Original after copy modification: ";
    s.print();

    MyString assigned;
    assigned = s;
    assigned.setChar(0, 'c');
    assert(assigned.getChar(0) == 'c');
    assert(s.getChar(0) == 'C');
    std::cout << "Assigned copy: ";
    assigned.print();
    std::cout << "Original after assignment modification: ";
    s.print();

    assigned = assigned;
    assigned.setString("");
    assert(assigned.size() == 0);

    return 0;
}