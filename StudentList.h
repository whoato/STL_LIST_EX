#pragma once
#include "Include.h"

class StudentList
{
private:
	list<Student> students;
	list<Student>::iterator iTerPos;
	list<Student>::iterator iTerEnd;
	char* studentName;
public:
	StudentList();
	~StudentList();
public:
	int Menu();
	void Add(check _check);
	void ChoiceClass(CLASSID _class);
	void Insert(int _where);
	void Alllist();
	void Search(char* name);
	void Delete(char* name);
	void Exit();
};

