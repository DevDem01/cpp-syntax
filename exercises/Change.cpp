#include <iostream>

void changeCopy(int x) {
    x = 99;
}

void changeOriginal(int& x) {
    x = 99;
}

void display(const int& x) {
    std::cout << x << '\n';
}

int main() {
    int score = 10;

    changeCopy(score);
    display(score);       // 10

    changeOriginal(score);
    display(score);       // 99
}