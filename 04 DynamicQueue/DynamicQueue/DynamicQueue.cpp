#include "DynamicQueue.h"
#include<iostream>

DynamicQueue::DynamicQueue():first(nullptr), rear(nullptr), size (0)
{}

DynamicQueue::~DynamicQueue()
{
	Node* Temp = first;

	while (first != nullptr)
	{
		Temp = first;
		first = first->next;
		delete Temp;
	}
	rear = nullptr;
}

bool DynamicQueue::IsFull()
{
	try
	{
		Node* testNode = new Node();
		delete testNode;
		return false;
	}
	catch (const std::exception badalloc)
	{
		return true;
	}
}

bool DynamicQueue::IsEmpty()
{
	return first == nullptr;
}

void DynamicQueue::Push(data data)
{

	if (IsFull())
	{
		std::cout << "No more memory space...\n";
		return;
	}

	Node* newNode = new Node();
	newNode->dt = data;
	newNode->next = nullptr;

	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		rear->next = newNode;
	}

	rear = newNode;
	size++;
}

data DynamicQueue::Pop()
{

	if (IsEmpty())
	{
		return data();
	}

	data returnValue = first->dt;
	Node* tempDestroy = first;
	
	first = first->next;
	if (first == nullptr)
	{
		rear = nullptr;
	}

	delete tempDestroy;
	size--;
	return returnValue;
}

void DynamicQueue::Print()
{

	if (IsEmpty())
	{
		std::cout << "Empty...\n";
		return;
	}

	Node* nodeToPrint = first;

	std::cout << "[ ";

	while (nodeToPrint != nullptr)
	{

		std::cout << nodeToPrint->dt;
		nodeToPrint = nodeToPrint->next;
		if (nodeToPrint != nullptr)
		{
			std::cout << ", ";
		}
	}

	std::cout << " ]\n";
}

int DynamicQueue::Length()
{
	return size;
}
