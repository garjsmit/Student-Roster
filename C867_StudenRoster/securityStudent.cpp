#include <iostream>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent() :Student()
{
	degree = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degree)
	: Student(studentID, firstName, lastName, email, age, daysToComplete, degree)
{
	degree = SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << degreeStrings[getDegreeProgram()] << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}