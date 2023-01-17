#include <iostream>
#include "BinaryTree.h"

int main()
{


	BinaryTree bst;

	bst.Insert(Student(4, "PPP"));
	bst.Insert(Student(6, "PPP"));
	bst.Insert(Student(1, "PPP"));
	bst.Insert(Student(3, "PPP"));
	bst.Insert(Student(5, "JJJ"));
	bst.Insert(Student(7, "PPP"));
	bst.Insert(Student(2, "PPP"));


	Student st(3, "");
	bool bFound = false;

	bst.Search(st, bFound);


	if (bFound)
	{
		std::cout << st.GetName() << "\n";
		std::cout << st.GetRN()<<"\n";
	}
	else
	{
		std::cout << st.GetRN() << " No Found!\n";
	}




	return 0;
}