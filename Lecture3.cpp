#include <iostream>
#include <string>

int main() {

    // int arr[3] = {1, 2, 3};
    // int* ptr = arr;

    // std::cout << arr[2] << ',' << *(ptr+2) << std::endl;

    // // *(ptr+3) = 10; // no safety check
    // arr[3] = 10;

    // C-style string
    char s1[] = "apple";
    // s1 = "banana";
    // strcpy(s1, "banana");
    char copy[10];

    std::cout << strlen(copy) << ',' << sizeof(copy) << std::endl;
    strcpy(copy, "banana");
    std::cout << strlen(copy) << ',' << sizeof(copy) << std::endl;

    // C++ string
    std::string s2;
    s2 = "banana";

    s2 += " 2nd";
    std::cout << s2 << std::endl;

    return 0;
}