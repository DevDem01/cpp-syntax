#include <iosfwd>

class MyString {
private:
    char* data;
    int length;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    int size() const;
    char getChar(int index) const;
    void setChar(int index, char c);
    void setString(const char* str);
    void print() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};