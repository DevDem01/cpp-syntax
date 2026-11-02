#ifndef LAB7_STACK_H
#define LAB7_STACK_H

#include <cassert>
#include <cstddef>

template <typename T, std::size_t N>
class Stack
{
private:
    T data[N];
    int topIndex;

public:
    Stack();
    void push(const T &value);
    void pop();
    T &top();
    const T &top() const;
    bool empty() const;
    int size() const;
};

template <typename T, std::size_t N>
Stack<T, N>::Stack()
    : topIndex(-1)
{
}

template <typename T, std::size_t N>
void Stack<T, N>::push(const T &value)
{
    assert(topIndex < static_cast<int>(N) - 1);
    data[++topIndex] = value;
}

template <typename T, std::size_t N>
void Stack<T, N>::pop()
{
    assert(!empty());
    --topIndex;
}

template <typename T, std::size_t N>
T &Stack<T, N>::top()
{
    assert(!empty());
    return data[topIndex];
}

template <typename T, std::size_t N>
const T &Stack<T, N>::top() const
{
    assert(!empty());
    return data[topIndex];
}

template <typename T, std::size_t N>
bool Stack<T, N>::empty() const
{
    return topIndex == -1;
}

template <typename T, std::size_t N>
int Stack<T, N>::size() const
{
    return topIndex + 1;
}

#endif
