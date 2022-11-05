#pragma once

#include "Vector.h"

namespace yazi {
namespace stl {

template <typename T>
class Array : public Vector<T>
{
public:
    Array() = delete;
    Array(int size, const T & value = T());
    ~Array();

    void push_back(const T & value) = delete;
    void pop_back() = delete;
    void reserve(int size) = delete;
    void resize(int size) = delete;
    void clear() = delete;
    Array<T> & operator = (const Array<T> & other) = delete;

    typedef typename Vector<T>::iterator iterator;
    typedef typename Vector<T>::reverse_iterator reverse_iterator;

    iterator insert(iterator pos, const T & value) = delete;
    iterator insert(iterator pos, int n, const T & value) = delete;
    iterator erase(iterator pos) = delete;
    iterator erase(iterator first, iterator last) = delete;

    void fill(const T & value);
};

template <typename T>
Array<T>::Array(int size, const T & value)
{
    this->m_data = new T[size];
    this->m_size = size;
    this->m_capacity = size;
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_data[i] = value;
    }
}

template <typename T>
Array<T>::~Array()
{
}

template <typename T>
void Array<T>::fill(const T & value)
{
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_data[i] = value;
    }
}

}
}