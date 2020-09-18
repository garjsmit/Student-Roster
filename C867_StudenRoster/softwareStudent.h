#pragma once
#include<string>
#include "student.h"

class SoftwareStudent : public Student
{

public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degree);

	Degree getDegreeProgram();
	void print();

	~SoftwareStudent(); //FIXME either remove everything that makes the array of daysToComplete dynamic (the daysCompArraySize = 3 in student.h or make a destructor here
};
