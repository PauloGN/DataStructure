#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{}

void BinaryTree::DeleteTree(Node * node)
{}

bool BinaryTree::IsEmpty()
{
    return root == nullptr;
}

bool BinaryTree::IsFull()
{

	try
	{
		Node* tryNode = new Node();
		delete tryNode;
		return false;
	}
	catch (std::bad_alloc exception)
	{	
		 return false;
	}

}

void BinaryTree::Insert(const Student student)
{
	
	if (IsFull())
	{
		std::cout << "BST is full.....\n";
		return;
	}

	if (student.GetRN() < 0 || student.GetName().length() == 0)
	{
		std::cout << "Invalid data for student...\n";
		return;
	}

	Node* node = new Node(student);

	if (root == nullptr)
	{
		root = node;
	}
	else
	{
		Node* tempNode = root;

		while (tempNode != nullptr)
		{
			if (student.GetRN() < tempNode->st.GetRN())
			{
				if (tempNode->Left == nullptr)
				{
					tempNode->Left = node;
					break;
				}
				else
				{
					tempNode = tempNode->Left;
				}
			}
			else
			{
				if (tempNode->Right == nullptr)
				{
					tempNode->Right = node;
					break;
				}
				else
				{
					tempNode = tempNode->Right;
				}
			}
		}
	}
}

void BinaryTree::Delete(Student student)
{}

void BinaryTree::Search(Student & student, bool& bFound)
{

	if (IsEmpty()) 
	{
		bFound = false;
		return;
	}

	Node* searchNode = root;

	while (searchNode != nullptr) 
	{

		if (student.GetRN() == searchNode->st.GetRN())
		{
			student = searchNode->st;
			bFound = true;
			break;
		}

		if (student.GetRN() < searchNode->st.GetRN()) {

			searchNode = searchNode->Left;
		}
		else 
		{
			searchNode = searchNode->Right;
		}
	}
}

void BinaryTree::PrintPreOrder(Node * node)
{}

void BinaryTree::PrintInOrder(Node * node)
{}

void BinaryTree::PrintPosOrder(Node * node)
{}
