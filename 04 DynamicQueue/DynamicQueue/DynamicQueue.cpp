#include "DynamicQueue.h"
#include<iostream>

DynamicQueue::DynamicQueue():first(nullptr), rear(nullptr), size (0)
{}

DynamicQueue::~DynamicQueue()
{
	const Node* Temp = first;

	while (first != nullptr)
	{
		Temp = first;
		first = first->next;
		delete Temp;
	}
	rear = nullptr;
}

DynamicQueue::DynamicQueue(const DynamicQueue& other)
{
	size = other.size;
	first = nullptr;
	rear = nullptr;

	const Node* nodeToClone = other.first;

	while (nodeToClone != nullptr)
	{
		Node* newNode = new Node();
		newNode->dt = nodeToClone->dt;
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
		nodeToClone = nodeToClone->next;
	}
}

DynamicQueue& DynamicQueue::operator=(const DynamicQueue& other)
{

	if(this == &other)
	{
		return *this;
	}

	if(first != nullptr)
	{
		const Node* nodeToDelete = first;
		while (first !=nullptr)
		{
			first = first->next;
			delete nodeToDelete;
			nodeToDelete = first;
		}

		first = nullptr;
		rear = nullptr;
	}

	size = other.size;

	const Node* nodeToClone = other.first;

	while (nodeToClone != nullptr)
	{
		Node* newNode = new Node();
		newNode->dt = nodeToClone->dt;
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
		nodeToClone = nodeToClone->next;
	}

	return *this;
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
