#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *data;
    int length;

public:
    MyString()
    {

        this->data = new char[1]{'\0'};
        this->length = 0;
    };
    MyString(const char *str)
    {
        int count = 0;
        while (str[count] != '\0')
        {
            count++;
        }
        this->length = count;
        this->data = new char[this->length + 1];
        for (int i = 0; i < count; i++)
        {
            data[i] = str[i];
        }
        data[count] = '\0';
    }
    MyString(const MyString &other)
    {
        this->length = other.length;
        this->data = new char[this->length + 1];
        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
        data[length] = '\0';
    }
    MyString &operator=(const MyString &other)
    {
        if (this == &other)
        {
            return *this;
        }

        return *this;
    }
    ~MyString()
    {
        delete[] data;
    }
    int size() const
    {

        return this->length;
    };
    char getChar(int index)
    {
        for (int i = 0; i < length)
    }

    ostream &operator<<(ostream &cout, const MyString &s) const
    {
        cout << s.data;
        return cout;
    }
    // const char getchar(int index){
    //       for(int i=0;i<this->data.strlen();i++){

    //       }

    // };
}
