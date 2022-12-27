#pragma once

typedef int data;
const int MAX_ITEM = 25;

class Queue_Array
{
private:

	int first;
	int rear;
	data* dataStruct;

public:

	Queue_Array();
	~Queue_Array();

	bool IsFull();
	bool IsEmpty();

	void Push(const data item);
	data Pop();
	int Length();
	void Print();
};

