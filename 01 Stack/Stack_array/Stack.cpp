#include "Stack.h"
#include<iostream>


Stack::Stack()
{
    size = 0;
    stack_dat = new data[MAX_SIZE];
}

Stack::~Stack()
{
    delete[] stack_dat;
}

bool Stack::IsEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

bool Stack::IsFull()
{
    if (size == MAX_SIZE)
    {
        return true;
    }
    return false;
}

void Stack::Push(const data item)
{
    if (IsFull()){return;}
    stack_dat[size++] = item;
}

data Stack::Pop()
{
    if (IsEmpty()){return data{};}
    data temp = stack_dat[--size];
    return temp;
}

void Stack::Print()
{
    std::cout << "[ ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << stack_dat[i];
        if (i + 1 < size)
        {
            std::cout << ", ";
        }
    }
    std::cout << " ]";
}

int Stack::Lengh()const
{
    return size;
}
