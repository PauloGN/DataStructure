#include<iostream>
#include"DynamicQueue.h"




int main()
{
	DynamicQueue data_structure;
	data item{ 0 };
	bool is_running = true;

	do
	{
		std::cout << "Program Generator of stack\n";
		std::cout << "Options: \n1 - Insert data\n2 - Pop data\n3 - See size of data structure\n4 - Print data\n5 - Exit\n";
		std::cout << "-> ";


		size_t op{ 0 };
		std::cin >> op;
		switch (op)
		{
		case 1:

			system("cls");
			if (data_structure.IsFull())
			{
				std::cout << "data structure is full: ";
				break;
			}
			std::cout << "Enter your data: ";
			std::cin >> item;
			data_structure.Push(item);

			break;
		case 2:
		{
			if (data_structure.IsEmpty())
			{
				std::cout << "data structure is already empty:\n";
				break;
			}

			const data tempDat = data_structure.Pop();
			std::cout << tempDat << " Removed succesfuly.\n";

			break;
		}
		case 3:

			std::cout << "Data structure current size: " << data_structure.Length() << std::endl;

			break;
		case 4:

			data_structure.Print();

			break;

		case 5:

			is_running = false;

			break;

		default:

			std::cout << "Invalid Option:\n";

			break;
		}
		system("pause");
		system("cls");
	} while (is_running);


	return 0;
}