#pragma once
#include<iomanip>

class Student;

/*
* Max_Items is the maximun of items to be added
* Max_Pos is the size of memory alocation
* 
* Load factor is the amount of elements divided by the max pos
*/

class Hash
{
private:

	int Max_Items;
	int Max_Pos;
	int Items_Amount;

	Student* DataStructure;

private:

	int HashFunction(Student student);
	
public:

	Hash(int max_pos);
	~Hash();
	bool IsFull();
	bool IsEmpty();
	int Size();

	void Push(Student student);
	Student Pop(Student student);
	void Search(Student& student, bool& search);
	void Print();

	float GetLoadFactor() const { return static_cast<float>( Max_Items /(float) Max_Pos);}

};