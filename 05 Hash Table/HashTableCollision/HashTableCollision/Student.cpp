#include "Student.h"

Student::Student():RN("void"), Name("Default")
{}

Student::Student(std::string rn, std::string name): RN(rn), Name(name)
{}

void Student::Print()
{

	std::cout << "Student Name: " << Name << std::endl;
	std::cout << "Student Register Number: " << RN << std::endl;
	std::cout<<"\t\t=====================================================\n";

}
