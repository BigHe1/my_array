#pragma once

#include<iostream>
using namespace std;

template<class T>
class my_array
{
private:
    T* m_address;   //数组地址
    int m_capacity; //数组容量
    int m_size;       //数组内有多少个数据


public:

    my_array(const int capacity);   //有参构造
    my_array(const my_array& array);//拷贝构造
    my_array& operator=(const my_array& head);    //拷贝赋值
    ~my_array();                       //析构函数
   
    void push_back(const T& val);   //尾插法
    void pop_out();     //尾删法

    T& operator[](const int index); //下标访问，作为左值要返回引用

    T* address() { return m_address; }

    int r_capacity()
    {
        return m_capacity;
    }
    int r_size()
    {
        return m_size;
    }

};

//普通构造
template<class T>
inline my_array<T>::my_array(const int capacity)
{
    m_capacity = capacity;
    m_address = new T[m_capacity];
    m_size = 0;
}

//拷贝赋值
template<class T>
inline my_array<T>& my_array<T>::operator=(const my_array& head)
{
    if(this == &head) return *this;

    if(m_address)
    {
        delete[] m_address;
        m_address = nullptr;
        m_capacity = 0;
        m_size = 0;
    }
    
    m_address = new T[head.m_capacity];
    m_capacity = head.m_capacity;
    m_size = head.m_size;

    for(int i = 0; i<head.m_capacity; i++)
        m_address[i] = head.m_address[i];

    return *this;
}

//拷贝构造
template<class T>
inline my_array<T>::my_array(const my_array& array)
{
    m_address = new T[array.m_capacity];
    m_size = array.m_size;
    m_capacity = array.m_capacity;

    for (int i = 0; i < array.m_capacity; i++)
        m_address[i] = array.m_address[i];
    
}

//析构函数
template<class T>
inline my_array<T>::~my_array()
{
        if(m_address)
        {
            delete[] m_address;
            m_address = nullptr; //指针置空，防止野指针
        }
}

//尾差法
template<class T>
inline void my_array<T>::push_back(const T& val)
{
    if(m_capacity == m_size) return;

    m_address[m_size] = val;
    m_size++;   //更新数组大小
}

//尾删法
//数组的内存是连续的，不能单独释放某个元素的内存
template<class T>
inline void my_array<T>::pop_out()
{
    if(m_size == 0) return; 
    m_size--;
}

//[]重载 可以下表访问
template<class T>
inline T& my_array<T>::operator[](const int index)
{
     return m_address[index];
}

