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

	// Rule of 5:
	DynamicQueue(const DynamicQueue& other);
	DynamicQueue& operator=(const DynamicQueue& other);

	DynamicQueue(DynamicQueue&& other) noexcept = delete;
	DynamicQueue& operator=(DynamicQueue&& other) noexcept = delete;

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