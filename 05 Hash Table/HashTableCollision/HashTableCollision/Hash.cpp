#include "Hash.h"
#include "Student.h"
#include <cmath>

int Hash::HashFunction(Student student)
{

	std::string rnREF = student.GetRN();

	unsigned int value{ 0 };

	for (size_t i = 0; i < rnREF.size(); i++)
	{

		const unsigned int temp = rnREF[i];
		value += temp * (pow(3, i));

		if (i > 9)
		{
			break;
		}

	}

	return value % Max_Pos;
}

Hash::Hash(int max_Items): Max_Items(max_Items), Items_Amount(0)
{

	if (Max_Items < 11)
	{
		Max_Items = 11;
	}

	if (Max_Items <= 100)
	{
		//extendes Max_Pos to 40% to suporte colisions;
		Max_Pos = (Max_Items * 0.4) + Max_Items;
		
	}
	else
	{
		//extendes Max_Pos to 30% to suporte colisions;
		Max_Pos = (Max_Items * 0.3) + Max_Items;
	}

	DataStructure = new Student [Max_Pos];

}

Hash::~Hash()
{
	delete[] DataStructure;
}

bool Hash::IsFull()
{
	return Items_Amount == Max_Pos;
}

bool Hash::IsEmpty()
{
	return Items_Amount == 0;
}

int Hash::Size()
{
	return Items_Amount;
}

void Hash::Push(Student student)
{

	if (IsFull())
	{
		return;
	}

	int index = HashFunction(student);

	while (DataStructure[index].GetRN() != "void" && DataStructure[index].GetRN() != "available")
	{

		if (DataStructure[index].GetRN() == student.GetRN())
		{
			std::cout << "Invalid operation the RN: " << DataStructure[index].GetRN() <<" has already been registered...\n";
			return;
		}

		index++;
		if (index >= Max_Pos)
		{
			index = 0;
		}
	}

	DataStructure[index] = student;
	Items_Amount++;

}

void Hash::Pop(Student student)
{

	int index = HashFunction(student), maxSearch{0};

	while (DataStructure[index].GetRN() != student.GetRN() && DataStructure[index].GetRN() != "void")
	{	
		index++;
		if (index >= Max_Pos)
		{
			index = 0;
		}
		maxSearch++;
		if (maxSearch >= Max_Pos)
		{
			break;
		}
	}

	bool bWasFound = DataStructure[index].GetRN() == student.GetRN();

	if (bWasFound)
	{
		Student sdDelete("available", "Defalut");
		std::cout << DataStructure[index].GetName() << " Removed succesfuly.\n";
		DataStructure[index] = sdDelete;
		Items_Amount--;
		return;
	}

	std::cout <<"Student register number: "<< student.GetRN() << ", not found...\n";

}

void Hash::Search(Student& student, bool& search)
{

	int index = HashFunction(student), maxSeach{0};

	while (DataStructure[index].GetRN() != student.GetRN() && DataStructure[index].GetRN() != "void")
	{
		//index = index + 1 % (Max_Pos - 1);
		index++;
		if (index >= Max_Pos)
		{
			index = 0;
		}
		maxSeach++;
		if (maxSeach >= Max_Pos)
		{
			break;
		}
	}

	if (DataStructure[index].GetRN() == student.GetRN())
	{
		search = true;
		student = DataStructure[index];
		return;
	}

	search = false;
}

void Hash::Print()
{

	std::cout << "\t\t========== Hash Table Collision ==========\n";

	if (IsEmpty())
	{
		std::cout << "Data structure is empty.....\n";
		return;
	}

	for (size_t i = 0; i < Max_Pos; i++)
	{
		if (DataStructure[i].GetRN() != "void" && DataStructure[i].GetRN() != "available")
		{
			std::cout << i + 1 << " - \n";
			DataStructure[i].Print();
		}
	}
}
