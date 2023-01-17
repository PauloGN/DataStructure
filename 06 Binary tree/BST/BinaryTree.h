#pragma once
#include "Student.h"

struct Node
{
	Student st;
	Node* Left{nullptr};
	Node* Right{nullptr};

	Node() = default;
	Node(Student rhs):st(rhs.GetRN(), rhs.GetName()), Left(nullptr), Right(nullptr){}

};


class BinaryTree
{

public:

	BinaryTree();
	~BinaryTree();

	void DeleteTree(Node* node);
	Node* GetRoot(){return root;};
	bool IsEmpty();
	bool IsFull();

	void Insert(const Student student);
	void Delete(Student student);
	void Search(Student& student, bool& bFound);

	void PrintPreOrder(Node* node);
	void PrintInOrder(Node* node);
	void PrintPosOrder(Node* node);

private:

	Node* root;

};

