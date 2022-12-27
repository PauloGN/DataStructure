#pragma once
#include<iostream>

typedef float Data;

struct Node
{
	Data dt;
	Node* next;
};


class DynamicStack
{
private:

	Node* top;
	int size;

public:

	DynamicStack();
	~DynamicStack();
	bool IsEmpty();
	bool IsFull();
	void Push(Data dt);
	Data Pop();
	void Print();
	int Lengh();
};

