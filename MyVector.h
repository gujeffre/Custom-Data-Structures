#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <utility>
#include <cstddef>

template <typename T>
class MyVector {
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    void Reallocate(size_t newCapacity) {
        T* newBlock = new T[newCapacity];
        for (size_t i = 0; i < m_Size; ++i) {
            newBlock[i] = std::move(m_Data[i]);
        }
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

public:
    MyVector() {
        Reallocate(2);
    }

    ~MyVector() {
        delete[] m_Data;
    }

    MyVector(const MyVector& other) : m_Size(other.m_Size), m_Capacity(other.m_Capacity) {
        m_Data = new T[m_Capacity];
        for (size_t i = 0; i < m_Size; ++i) {
            m_Data[i] = other.m_Data[i];
        }
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;
        delete[] m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_Data = new T[m_Capacity];
        for (size_t i = 0; i < m_Size; ++i) {
            m_Data[i] = other.m_Data[i];
        }
        return *this;
    }

    MyVector(MyVector&& other) noexcept 
        : m_Data(other.m_Data), m_Size(other.m_Size), m_Capacity(other.m_Capacity) {
        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;
    }

    MyVector& operator=(MyVector&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_Data;
        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;
        return *this;
    }

    void PushBack(const T& value) {
        if (m_Size >= m_Capacity) {
            Reallocate(m_Capacity * 2);
        }
        m_Data[m_Size++] = value;
    }

    void PushBack(T&& value) {
        if (m_Size >= m_Capacity) {
            Reallocate(m_Capacity * 2);
        }
        m_Data[m_Size++] = std::move(value);
    }

    void PopBack() {
        if (m_Size > 0) {
            m_Size--;
            m_Data[m_Size] = T(); 
        }
    }

    size_t Size() const { return m_Size; }
    size_t Capacity() const { return m_Capacity; }
    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }
};

#endif
