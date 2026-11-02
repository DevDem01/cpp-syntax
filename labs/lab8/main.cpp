#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename Iterator, typename T>
Iterator myRemove(Iterator first, Iterator last, const T& value) {
    Iterator write = first;

    for (Iterator read = first; read != last; ++read) {
        if (*read != value) {
            *write = *read;
            ++write;
        }
    }

    return write;
}

template <typename Iterator>
Iterator myUnique(Iterator first, Iterator last) {
    if (first == last) {
        return first;
    }

    Iterator result = first;
    for (Iterator current = first; ++current != last; ) {
        if (*current != *result) {
            ++result;
            *result = *current;
        }
    }

    return ++result;
}

template <typename Iterator, typename T>
Iterator binarySearch(Iterator first, Iterator last, const T& target) {
    using DifferenceType = typename std::iterator_traits<Iterator>::difference_type;

    DifferenceType left = 0;
    DifferenceType right = last - first;

    while (left < right) {
        DifferenceType mid = left + (right - left) / 2;
        Iterator midIt = first + mid;

        if (*midIt == target) {
            return midIt;
        }

        if (*midIt < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return last;
}

void printRange(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
}

void printRange(const std::list<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 2, 4, 2};
    auto newEnd1 = myRemove(numbers.begin(), numbers.end(), 2);
    numbers.erase(newEnd1, numbers.end());
    printRange(numbers);

    std::list<int> values = {1, 2, 3, 2, 4, 2};
    auto newEnd2 = myRemove(values.begin(), values.end(), 2);
    values.erase(newEnd2, values.end());
    printRange(values);

    std::vector<int> uniqueNumbers = {1, 1, 2, 2, 2, 3, 4, 4};
    auto newUniqueEnd1 = myUnique(uniqueNumbers.begin(), uniqueNumbers.end());
    uniqueNumbers.erase(newUniqueEnd1, uniqueNumbers.end());
    printRange(uniqueNumbers);

    std::list<int> uniqueValues = {1, 1, 2, 2, 2, 3, 4, 4};
    auto newUniqueEnd2 = myUnique(uniqueValues.begin(), uniqueValues.end());
    uniqueValues.erase(newUniqueEnd2, uniqueValues.end());
    printRange(uniqueValues);

    std::vector<int> v = {1, 3, 5, 7, 9};
    auto it = binarySearch(v.begin(), v.end(), 7);
    if (it != v.end()) {
        std::cout << "Found : " << *it << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    std::vector<double> n = {10.1, 23.5, 68.3, 77.7, 84.9, 95.8};
    auto it2 = binarySearch(n.begin(), n.end(), 10.0);
    if (it2 != n.end()) {
        std::cout << "Found : " << *it2 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}