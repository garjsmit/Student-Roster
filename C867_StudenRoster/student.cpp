#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) { this->daysToComplete[i] = 0; }
	this->degree = SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degree = degree;

}

//getters
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int* Student::getDaysToComplete() { return daysToComplete; }


//setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToComplete(int daysToComplete[])
{
	for (int i = 0; i < 3 ; i++)
		this->daysToComplete[i] = daysToComplete[i];
}

void Student::print()
{
	int* days = getDaysToComplete();
	cout << left << setw(5) << getStudentID();
	cout << left << setw(12) << getFirstName();
	cout << left << setw(15) << getLastName();
	cout << left << setw(25) << getEmail();
	cout << left << setw(8) << getAge();
	for (int i = 0; i < 3; i++) cout << left << setw(7)<< days[i];

}

Student::~Student() 
{
	
}
