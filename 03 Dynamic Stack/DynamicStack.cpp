#include "DynamicStack.h"

DynamicStack::DynamicStack()
{
    top = nullptr;
    size = 0;
}

DynamicStack::~DynamicStack()
{
	const Node* NodeToDestroy = nullptr;

    while (top != nullptr)
    {
        NodeToDestroy = top;
        top = top->next;
        delete NodeToDestroy;
    }
}

bool DynamicStack::IsEmpty()
{
    return (top == nullptr);
}

bool DynamicStack::IsFull()
{
    try
    {
	    const Node* testNode = new Node();
        delete testNode;
        return false;
    }
    catch (std::bad_alloc exception)
    {
         return true;    
    }
}

void DynamicStack::Push(Data dt)
{
    if (IsFull())
    {
        return;
    }

    Node* newNode = new Node();
    newNode->dt = dt;
    newNode->next = top;

    top = newNode;
    size++;
}

Data DynamicStack::Pop()
{
    if (IsEmpty())
    {
        return Data();
    }

    const Data tempData = std::move(top->dt);

    Node* NodeToDestroy = top;
    top = top->next;
    delete NodeToDestroy;
    size--;
    return tempData;
}

void DynamicStack::Print()
{
	const Node* NodeToPrint = top;
    std::cout << "Dymanic Stack [ ";

    while (NodeToPrint != nullptr)
    {
        std::cout << NodeToPrint->dt << " ";
        NodeToPrint = NodeToPrint->next;
    }
    std::cout << "]\n";
}

int DynamicStack::Lengh() const
{
    return size;
}