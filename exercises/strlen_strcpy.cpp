#include <iostream>
#include <string>
using namespace std;

int MyStrlen(const char* s) {
    int sum = 0;

    // Loops through given string until null terminator is reached
    while (*s != '\0') {
        sum++;
        s++;
    }

    return sum;
}

void Mystrcpy(char* des, const char* src) {
    // Copy characters until null terminator
    while (*src) {
        *des = *src;

        des++;
        src++;
    }

    // Include null terminator in the copy
    *des = '\0';
}

// Version 1: std::string
int countChar(const string& s, char target) {
    int occur = 0;

    for (char c : s) {
        if (c == target) {
            occur++;
        }
    }

    return occur;
}

// Version 2: C-style string using pointer arithmetic
int countChar(const char* s, char target) {
    int occur = 0;

    while (*s != '\0') {
        if (*s == target) {
            occur++;
        }

        s++;
    }

    return occur;
}

int findMax(const int arr[], int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

double computeAverage(const int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];

        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {

    char a[] = "Frog";
    char b[sizeof(a)];

    Mystrcpy(b, a);

    cout << "Number of characters of a: " << MyStrlen(a) << endl;
    cout << "Copy: " << b << endl;

    // Calls C-style string version
    cout << "The occurrence of target character: "
         << countChar("Demarcus", 'D') << endl;

    // Calls std::string version
    string name = "Demarcus";
    cout << "The occurrence using string version: "
         << countChar(name, 'D') << endl;

    int numbers[10];

    cout << "Enter 10 integers: ";

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

    cout << "Max: " << findMax(numbers, 10) << endl;
    cout << "Average: " << computeAverage(numbers, 10) << endl;

    reverseArray(numbers, 10);

    cout << "Reversed array: ";
    printArray(numbers, 10);

    return 0;
}