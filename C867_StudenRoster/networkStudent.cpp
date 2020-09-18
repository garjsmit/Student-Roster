#include <iostream>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() :Student()
{
	degree = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degree)
	: Student(studentID, firstName, lastName, email, age, daysToComplete, degree)
{
	degree = NETWORK;
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << degreeStrings[getDegreeProgram()] << endl;
}


NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}