#pragma once

const int MAX_SIZE = 20;
typedef int data;

class Stack
{
private:

	data* stack_dat;
	unsigned size;

public:

	Stack();
	~Stack();

	bool IsEmpty() const;
	bool IsFull();
	void Push(const data item);
	data Pop();
	void Print();
	int Lengh() const;
};