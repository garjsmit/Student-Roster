#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() : Student()
{
	degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degree)
	: Student(studentID, firstName, lastName, email, age, daysToComplete, degree)
{
	degree = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << degreeStrings[getDegreeProgram()] << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}