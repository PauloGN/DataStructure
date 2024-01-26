#pragma once

typedef int data;
constexpr int MAX_ITEM = 25;

class Queue_Array
{
private:

	int first;
	int rear;
	data* dataStruct;

public:

	Queue_Array();
	~Queue_Array();

	bool IsFull() const;
	bool IsEmpty() const;

	void Push(const data item);
	data Pop();
	int Length() const;
	void Print() const;
};