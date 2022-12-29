#include "Hash.h"
#include "Student.h"
#include <cmath>

int Hash::HashFunction(Student student)
{

	std::string rnREF = student.GetRN();

	int value{ 0 };

	for (size_t i = 0; i < rnREF.size(); i++)
	{

		const int temp = rnREF[i];

		value += temp * (pow(3, i));
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
	return Max_Items == Items_Amount;
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

	int idex = HashFunction(student);
	DataStructure[idex] = student;
	Items_Amount++;

}

Student Hash::Pop(Student student)
{

	int idex = HashFunction(student);
	Student sd, sdReturned;
	
	if (DataStructure[idex].GetRN() != "void" && DataStructure[idex].GetRN() == student.GetRN())
	{
		sdReturned = DataStructure[idex];
		DataStructure[idex] = sd;
		Items_Amount--;
	}

	return sdReturned;
}

void Hash::Search(Student& student, bool& search)
{

	int idex = HashFunction(student);

	if (DataStructure[idex].GetRN() == student.GetRN())
	{
		search = true;
		student = DataStructure[idex];
		return;
	}

	search = false;
}

void Hash::Print()
{

	std::cout << "\t\t========== Hash Table No Collision==========\n";

	for (size_t i = 0; i < Max_Pos; i++)
	{
		if (DataStructure[i].GetRN() != "void")
		{
			std::cout << i + 1 << " - \n";
			DataStructure[i].Print();
		}
	}
}
