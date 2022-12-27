#include "Queue_Array.h"
#include<iostream>

Queue_Array::Queue_Array()
{
    first = 0;
    rear = 0;

    dataStruct = new data[MAX_ITEM];

}

Queue_Array::~Queue_Array()
{
    delete[]dataStruct;
}

bool Queue_Array::IsFull()
{
    if (rear - first == MAX_ITEM)
    {
        return true;
    }
    return false;
}

bool Queue_Array::IsEmpty()
{
    if (first == rear)
    {
        return true;
    }
    return false;
}

void Queue_Array::Push(const data item)
{
    dataStruct[rear++ % MAX_ITEM] = item;
}

data Queue_Array::Pop()
{
    const data tempData = dataStruct[first % MAX_ITEM];
    first++;
    return tempData;
}

int Queue_Array::Length()
{
    return rear - first;
}

void Queue_Array::Print()
{

    if (IsEmpty())
    {
        return;
    }

    std::cout << "[ ";
    for (size_t i = first; i < rear; i++)
    {
        const size_t index = i % MAX_ITEM;

        std::cout << dataStruct[index];
        if (i + 1 < rear)
        {
            std::cout << ", ";
        }
    }
    std::cout << " ]";
}
