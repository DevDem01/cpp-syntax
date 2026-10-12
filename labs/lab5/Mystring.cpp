#include "Mystring.h"

#include <iostream>
#include <stdexcept>

MyString::MyString() : data(new char[1]{'\0'}), length(0) {}

MyString::MyString(const char* str) : data(nullptr), length(0) {
    setString(str);
}

MyString::MyString(const MyString& other)
    : data(new char[other.length + 1]), length(other.length) {
    for (int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
    data[length] = '\0';
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        char* newData = new char[other.length + 1];
        for (int i = 0; i < other.length; ++i) {
            newData[i] = other.data[i];
        }
        newData[other.length] = '\0';

        delete[] data;
        data = newData;
        length = other.length;
    }
    return *this;
}

MyString::~MyString() {
    delete[] data;
}

int MyString::size() const {
    return length;
}

char MyString::getChar(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("MyString character index is out of range");
    }
    return data[index];
}

void MyString::setChar(int index, char c) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("MyString character index is out of range");
    }
    data[index] = c;
}

void MyString::setString(const char* str) {
    if (str == nullptr) {
        throw std::invalid_argument("MyString cannot be set from a null pointer");
    }

    int newLength = 0;
    while (str[newLength] != '\0') {
        ++newLength;
    }

    char* newData = new char[newLength + 1];
    for (int i = 0; i < newLength; ++i) {
        newData[i] = str[i];
    }
    newData[newLength] = '\0';

    delete[] data;
    data = newData;
    length = newLength;
}

void MyString::print() const {
    std::cout << data << std::endl;
}
