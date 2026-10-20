#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H

template <typename T>
class MyUniquePtr {
private:
    T* m_Ptr = nullptr;

public:
    MyUniquePtr() : m_Ptr(nullptr) {}
    explicit MyUniquePtr(T* ptr) : m_Ptr(ptr) {}

    ~MyUniquePtr() {
        delete m_Ptr;
    }

    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept : m_Ptr(other.m_Ptr) {
        other.m_Ptr = nullptr;
    }

     MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this == &other) return *this;
        delete m_Ptr;
        m_Ptr = other.m_Ptr;
        other.m_Ptr = nullptr;
        return *this;
    }

    T& operator*() const { return *m_Ptr; }
    T* operator->() const { return m_Ptr; }
    T* Get() const { return m_Ptr; }
    explicit operator bool() const { return m_Ptr != nullptr; }
};

#endif
