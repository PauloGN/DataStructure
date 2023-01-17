#pragma once
#include <iostream>

class Student
{

public:


	Student();
	Student(int RN, std::string Name);

	std::string GetName()const{ return Name;}
	int GetRN()const{return RN; }


private:

	int RN;
	std::string Name;

};

