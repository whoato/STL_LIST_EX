#pragma once
typedef struct studentInfo
{
	char* userName;
	int iKor;
	int iEng;

	studentInfo(char* _name, int _ikor, int _ieng)
		:userName(_name), iKor(_ikor), iEng(_ieng) {}

}Student;