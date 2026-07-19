/*
 * project   : https://github.com/Robin005cr/100_days_cpp_challenge
 * file name : unique_ptr.cpp
 * author    : Robin CR
 * mail id   : robinchovallurraju@gmail.com
 * LinkedIn  : https://www.linkedin.com/in/robin-cr/
 * portfolio : https://robin005cr.github.io/
 *
 * Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
 * Suggestions for improvements or better methods are always welcome and appreciated.
 * I value constructive feedback and aim to continuously improve the quality of the work.
 *
 */
#include <iostream>
using namespace std;
template <typename T>
class UniquePointer
{
    T *ptr;

public:
    explicit UniquePointer(T *p = nullptr) : ptr(p)
    {
        cout << "ctor called" << endl;
    }
    ~UniquePointer()
    {
        delete ptr;
    }

    // restricting the copy operations

    UniquePointer(const UniquePointer &) = delete;
    UniquePointer &operator=(const UniquePointer &) = delete;

    UniquePointer(const UniquePointer &&other) : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    UniquePointer &operator=(const UniquePointer &&other)
    {
        if (this != other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T *operator->() { return ptr; }
    T &operator*() { return *ptr; }
};
int main()
{
    auto *p = new int(10);
    UniquePointer<int> demoPtr(p);
    cout << *demoPtr;

    return 0;
}