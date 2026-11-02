#include <cassert>
#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "Stack.h"

int main()
{
    Stack<int, 5> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    std::cout << "Integer stack size: " << intStack.size() << std::endl;
    std::cout << "Top element: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "Top after pop: " << intStack.top() << std::endl;

    Stack<std::string, 3> stringStack;
    stringStack.push("C++");
    stringStack.push("Template");
    std::cout << "\nString stack size: " << stringStack.size() << std::endl;
    std::cout << "Top element: " << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << "Top after pop: " << stringStack.top() << std::endl;
    std::cout << "Is stack empty? " << stringStack.empty() << std::endl;

    DynamicArray<int> numbers;
    std::cout << "\nInitial size: " << numbers.size() << std::endl;
    std::cout << "Initial capacity: " << numbers.getCapacity() << std::endl;
    numbers.pushBack(10);
    numbers.pushBack(20);
    std::cout << "\nAfter adding two elements:" << std::endl;
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Capacity: " << numbers.getCapacity() << std::endl;
    numbers.pushBack(30);
    std::cout << "\nAfter adding another element:" << std::endl;
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Capacity: " << numbers.getCapacity() << std::endl;
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    DynamicArray<std::string> words;
    words.pushBack("C++");
    words.pushBack("Template");
    words.pushBack("Vector");
    std::cout << "\nString array:" << std::endl;
    for (std::size_t i = 0; i < words.size(); ++i)
    {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;

    DynamicArray<int> copiedNumbers(numbers);
    copiedNumbers[0] = 99;
    assert(numbers[0] == 10);
    DynamicArray<int> assignedNumbers;
    assignedNumbers = numbers;
    assignedNumbers[0] = 88;
    assert(numbers[0] == 10);
    assignedNumbers = assignedNumbers;

    const DynamicArray<int> constNumbers(numbers);
    assert(constNumbers[0] == 10);
    const Stack<int, 5> constStack(intStack);
    assert(constStack.top() == 20);

    return 0;
}
