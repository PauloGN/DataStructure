#pragma once

typedef int data;

struct Node
{
	data dt;
	Node* next;
};

class DynamicQueue
{

public:

	DynamicQueue();
	~DynamicQueue();
	bool IsFull();
	bool IsEmpty();
	void Push(data data);
	data Pop();
	void Print();
	int Length();

private:

	Node* first;//remove
	Node* rear;//add
	int size;
};

