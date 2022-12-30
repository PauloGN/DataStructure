#pragma once
#include<iomanip>

class Student;

/*
  Fator de carga é a quantidade de elementos dividido pela maximo de itens a serem inseridos;
  max elements X Max pos
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
	void Pop(Student student);
	void Search(Student& student, bool& search);
	void Print();

	float GetLoadFactor() const { return static_cast<float>( Max_Items /(float) Max_Pos);}

};

