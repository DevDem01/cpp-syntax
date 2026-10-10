#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float grade1, grade2, grade3;
    
    cout << "Please enter the first grade: ";
    cin >> grade1;
    cout << "Please enter the second grade: ";
    cin >> grade2;
    cout << "Please enter the third grade: ";
    cin >> grade3;

    float avg = (grade1 + grade2 + grade3) / 3;
    int rounded_avg = round(avg);
    
    if (rounded_avg >= 90) {
        cout << "Average: " << avg << endl;
        cout << "Grade: A" << endl;
    }
    else if (rounded_avg >= 80) {
        cout << "Average: " << avg << endl;
        cout << "Grade: B" << endl;
    }
    else if (rounded_avg >= 70) {
        cout << "Average: " << avg << endl;
        cout << "Grade: C" << endl;
    }
    else if (rounded_avg >= 60) {
        cout << "Average: " << avg << endl;
        cout << "Grade: D" << endl;
    }
    else {
        cout << "Average: " << avg << endl;
        cout << "Grade: F" << endl;
    }

    return 0;
}