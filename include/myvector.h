#include <iostream>
using namespace std;
template <typename T>
class MyVector
{
    int capacity;
    int size;
    T *data;
    T *enddress;

public:
    MyVector()
    {
        capacity = 0;
        size = 0;
        data = NULL;
        enddress = NULL;
    }
    MyVector(int num)
    {
        capacity = num;
        size = num;
        data = (T *)::operator new(num * sizeof(T));
        enddress = data + num;
        for (int i = 0; i < num; ++i)
        {
            ::operator new(sizeof(T), data + i);
        }
    }
    ~MyVector()
    {
        for (int i =size-1; i <0; --i)
        {
            delete (data + i);
        }
    }
    void pushback(T &one)
    {
    }
    T &operator[](int i)
    {
        return *(data + i);
    }
    T *getbegin()
    {
        return data;
    }
};