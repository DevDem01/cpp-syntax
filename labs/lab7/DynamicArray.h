#ifndef LAB7_DYNAMIC_ARRAY_H
#define LAB7_DYNAMIC_ARRAY_H

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <limits>
#include <memory>
#include <stdexcept>

template <typename T>
class DynamicArray
{
private:
    T *data;
    std::size_t currentSize;
    std::size_t capacity;

public:
    DynamicArray();
    DynamicArray(const DynamicArray<T> &other);
    DynamicArray<T> &operator=(const DynamicArray<T> &other);
    ~DynamicArray();
    void pushBack(const T &value);
    T &operator[](std::size_t index);
    const T &operator[](std::size_t index) const;
    std::size_t size() const;
    std::size_t getCapacity() const;
};

template <typename T>
DynamicArray<T>::DynamicArray()
    : data(new T[2]), currentSize(0), capacity(2)
{
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
    : data(nullptr), currentSize(other.currentSize), capacity(other.capacity)
{
    std::unique_ptr<T[]> newData(new T[capacity]);
    std::copy(other.data, other.data + currentSize, newData.get());
    data = newData.release();
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other)
{
    if (this != &other)
    {
        std::unique_ptr<T[]> newData(new T[other.capacity]);
        std::copy(other.data, other.data + other.currentSize, newData.get());

        delete[] data;
        data = newData.release();
        currentSize = other.currentSize;
        capacity = other.capacity;
    }
    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template <typename T>
void DynamicArray<T>::pushBack(const T &value)
{
    if (currentSize == capacity)
    {
        if (capacity > std::numeric_limits<std::size_t>::max() / 2)
        {
            throw std::length_error("DynamicArray capacity overflow");
        }

        const std::size_t newCapacity = capacity * 2;
        std::unique_ptr<T[]> newData(new T[newCapacity]);
        std::copy(data, data + currentSize, newData.get());
        newData[currentSize] = value;

        delete[] data;
        data = newData.release();
        capacity = newCapacity;
        ++currentSize;
        return;
    }

    data[currentSize++] = value;
}

template <typename T>
T &DynamicArray<T>::operator[](std::size_t index)
{
    assert(index < currentSize);
    return data[index];
}

template <typename T>
const T &DynamicArray<T>::operator[](std::size_t index) const
{
    assert(index < currentSize);
    return data[index];
}

template <typename T>
std::size_t DynamicArray<T>::size() const
{
    return currentSize;
}

template <typename T>
std::size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}

#endif
