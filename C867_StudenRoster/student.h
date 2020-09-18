#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];
	Degree degree; //virtual type

public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degree);

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	virtual Degree getDegreeProgram() = 0; //pure virtual function. will be defined within the subclasses

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);

	virtual void print() = 0;  //pure virtual function. will be defined within the subclasses

	//destructor
	~Student();
};
