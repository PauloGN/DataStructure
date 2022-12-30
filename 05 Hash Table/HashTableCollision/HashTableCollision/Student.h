#pragma once
#include<iostream>

class Student
{
private:

	std::string RN;
	std::string Name;

public:

	Student();
	Student(std::string rn, std::string name);
	std::string GetRN()const{ return RN; }
	std::string GetName(){ return Name;}
	void Print();


};

