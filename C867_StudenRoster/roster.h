#pragma once
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster {
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;
public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(string studentdata);
	void add(string studentID, string firstName, string lastName, string email, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, Degree degree);
	void remove(string studentID);
	void printAll();
	void printAveDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int d);

	~Roster();
};