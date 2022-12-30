#include<iostream>
#include "Hash.h"
#include "Student.h"
#include <string>


int main()
{

	//variables
	int op{ 0 };


	std::cout << "Please enter the initial size of the data structure:\n";
	std::cout << "-> ";
	std::cin >> op;
	Hash data_structure(op);
	std::cout << "Load Factor: "<< std::setprecision(2) << data_structure.GetLoadFactor()<<std::endl;

	bool is_running = true;
	bool search = false;

	std::string studentRn;
	std::string studentName;

	do
	{
		std::cout << "Program Generator of Hash table\n";
		std::cout << "Options: \n0 - See Load factor\n1 - Insert data\n2 - Pop data\n3 - See size of data structure\n4 - Print data\n5 - Search and update\n9 - Exit\n";
		std::cout << "-> ";


		size_t op{ 0 };
		std::cin >> op;
		
		std::cin.ignore();
		switch (op)
		{

		case 0:
		{

			std::cout << "Load Factor: " << std::setprecision(2) << data_structure.GetLoadFactor() << std::endl;

			break;
		}
		case 1:

			system("cls");
			if (data_structure.IsFull())
			{
				std::cout << "data structure is full: ";
				break;
			}

			std::cout << "Enter with student name: ";
			std::getline(std::cin, studentName);

			std::cout << "Enter with student Rn: ";
			std::getline(std::cin, studentRn);
			
			data_structure.Push(Student(studentRn, studentName));

			break;
		case 2:
		{
			if (data_structure.IsEmpty())
			{
				std::cout << "data structure is already empty:\n";
				break;
			}

			std::cout << "Enter with student Rn to be deleted: ";
			std::getline(std::cin, studentRn);

			data_structure.Pop(Student(studentRn, "Default"));
			
			break;
		}
		case 3:

			std::cout << "Data structure current size: " << data_structure.Size() << std::endl;

			break;
		case 4:

			data_structure.Print();

			break;
		case 5:
		{
			std::cout << "Enter with student Rn: ";
			std::getline(std::cin, studentRn);

			Student tempSTd(studentRn, "Default");
			data_structure.Search(tempSTd, search);

			if (search)
			{
				search = false;
				tempSTd.Print();
			}
			else
			{
				std::cout << "Student not fould...\n";
			}

		}
			break;
		case 9:

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