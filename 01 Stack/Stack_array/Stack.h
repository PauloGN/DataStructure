#pragma once

const int MAX_SIZE = 25;
typedef int data;

class Stack
{
private:

	data* stack_dat;
	int size;

public:

	Stack();
	~Stack();

	bool IsEmpty();
	bool IsFull();
	void Push(const data inten);
	data Pop();
	void Print();
	int Lengh() const;
};

