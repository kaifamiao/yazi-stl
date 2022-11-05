#pragma once

#include <iostream>
#include <stdexcept>

namespace yazi {
namespace stl {

template <typename T>
class Array
{
public:
    Array();
    Array(int size, const T & value = T());
    ~Array();

    int size() const;
    void show() const;
    T & at(int index);
    T & front();
    T & back();
    bool empty() const;
    T & operator [] (int index);
    T * data();
    void swap(Array<T> & other);

    class iterator
    {
    public:
        iterator() : m_pointer(nullptr) {}
        iterator(T * pointer) : m_pointer(pointer) {}
        ~iterator() {}

        bool operator == (const iterator & other)
        {
            return m_pointer == other.m_pointer;
        }
        
        bool operator != (const iterator & other)
        {
            return m_pointer != other.m_pointer;
        }

        iterator & operator = (const iterator & other)
        {
            m_pointer = other.m_pointer;
            return *this;
        }

        iterator & operator ++ ()
        {
            m_pointer += 1;
            return *this;
        }

        iterator operator ++ (int)
        {
            iterator it = *this;
            ++(*this);
            return it;
        }

        iterator operator + (int i)
        {
            iterator it = *this;
            it.m_pointer += i;
            return it;
        }

        iterator & operator += (int i)
        {
            m_pointer += i;
            return *this;
        }

        iterator operator - (int i)
        {
            iterator it = *this;
            it.m_pointer -= i;
            return it;
        }

        iterator & operator -= (int i)
        {
            m_pointer -= i;
            return *this;
        }

        int operator - (const iterator & other) const
        {
            return m_pointer - other.m_pointer;
        }

        T & operator * ()
        {
            return *m_pointer;
        }

        T * operator -> ()
        {
            return m_pointer;
        }

    private:
        T * m_pointer;
    };

    iterator begin();
    iterator end();

    class reverse_iterator
    {
    public:
        reverse_iterator() : m_pointer(nullptr) {}
        reverse_iterator(T * pointer) : m_pointer(pointer) {}
        ~reverse_iterator() {}

        bool operator == (const reverse_iterator & other)
        {
            return m_pointer == other.m_pointer;
        }
        
        bool operator != (const reverse_iterator & other)
        {
            return m_pointer != other.m_pointer;
        }

        reverse_iterator & operator = (const reverse_iterator & other)
        {
            m_pointer = other.m_pointer;
            return *this;
        }

        reverse_iterator & operator ++ ()
        {
            m_pointer -= 1;
            return *this;
        }

        reverse_iterator operator ++ (int)
        {
            reverse_iterator it = *this;
            ++(*this);
            return it;
        }

        reverse_iterator operator + (int i)
        {
            reverse_iterator it = *this;
            it.m_pointer -= i;
            return it;
        }

        reverse_iterator & operator += (int i)
        {
            m_pointer -= i;
            return *this;
        }

        reverse_iterator operator - (int i)
        {
            reverse_iterator it = *this;
            it.m_pointer += i;
            return it;
        }

        reverse_iterator & operator -= (int i)
        {
            m_pointer += i;
            return *this;
        }

        T & operator * ()
        {
            return *m_pointer;
        }

        T * operator -> ()
        {
            return m_pointer;
        }

    private:
        T * m_pointer;
    };

    reverse_iterator rbegin();
    reverse_iterator rend();

    iterator find(const T & value);
    iterator rfind(const T & value);

    void fill(const T & value);

protected:
    T * m_data;
    int m_size;
};

template <typename T>
Array<T>::Array() : m_data(nullptr), m_size(0)
{
}

template <typename T>
Array<T>::Array(int size, const T & value)
{
    if (size <= 0)
    {
        throw std::logic_error("invalid size");
    }
    m_data = new T[size];
    m_size = size;
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = value;
    }
}

template <typename T>
Array<T>::~Array()
{
    if (m_data != nullptr)
    {
        delete [] m_data;
        m_data = nullptr;
    }
    m_size = 0;
}

template <typename T>
int Array<T>::size() const
{
    return m_size;
}

template <typename T>
void Array<T>::show() const
{
    std::cout << "size=" << size() << std::endl;
    for (int i = 0; i < m_size; i++)
    {
        std::cout << m_data[i] << ",";
    }
    std::cout << std::endl;
}

template <typename T>
T & Array<T>::at(int index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::logic_error("out of range");
    }
    return m_data[index];
}

template <typename T>
T & Array<T>::front()
{
    if (m_size <= 0)
    {
        throw std::logic_error("array is empty");
    }
    return m_data[0];
}

template <typename T>
T & Array<T>::back()
{
    if (m_size <= 0)
    {
        throw std::logic_error("array is empty");
    }
    return m_data[m_size - 1];
}

template <typename T>
bool Array<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
T & Array<T>::operator [] (int index)
{
    return at(index);
}

template <typename T>
T * Array<T>::data()
{
    return m_data;
}

template <typename T>
void Array<T>::swap(Array<T> & other)
{
    T * data = other.m_data;
    int size = other.m_size;

    other.m_data = m_data;
    other.m_size = m_size;

    m_data = data;
    m_size = size;
}

template <typename T>
typename Array<T>::iterator Array<T>::begin()
{
    Array<T>::iterator it(m_data);
    return it;
}

template <typename T>
typename Array<T>::iterator Array<T>::end()
{
    Array<T>::iterator it(m_data + m_size);
    return it;
}

template <typename T>
typename Array<T>::reverse_iterator Array<T>::rbegin()
{
    Array<T>::reverse_iterator it(m_data + m_size - 1);
    return it;
}

template <typename T>
typename Array<T>::reverse_iterator Array<T>::rend()
{
    Array<T>::reverse_iterator it(m_data - 1);
    return it;
}

template <typename T>
typename Array<T>::iterator Array<T>::find(const T & value)
{
    for (Array<T>::iterator it = begin(); it != end(); it++)
    {
        if (*it == value)
        {
            return it;
        }
    }
    return end();
}

template <typename T>
typename Array<T>::iterator Array<T>::rfind(const T & value)
{
    for (Array<T>::reverse_iterator it = rbegin(); it != rend(); it++)
    {
        if (*it == value)
        {
            return Array<T>::iterator(it.operator->());
        }
    }
    return end();
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