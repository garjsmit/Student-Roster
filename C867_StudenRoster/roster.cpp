#include <iostream>
#include <iomanip>
#include "roster.h"
#include "degree.h"
using namespace std;

Roster::Roster() {
    this->lastIndex = -1; //any positive integer is a valid index, so this must be negative
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentAt(int index)
{
    return classRosterArray[index];
}

void Roster::parseThenAdd(string studentdata)
{
    if (lastIndex < capacity)
    {
        lastIndex++;
        int enditem = studentdata.find(",", 0);
        string studentID = studentdata.substr(0, enditem);

        int beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        string firstName = studentdata.substr(beginitem, enditem - beginitem);

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        string lastName = studentdata.substr(beginitem, enditem - beginitem);

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        string email = studentdata.substr(beginitem, enditem - beginitem);

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        int age = stoi(studentdata.substr(beginitem, enditem - beginitem));

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        int daysToComplete1 = stoi(studentdata.substr(beginitem, enditem - beginitem));

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        int daysToComplete2 = stoi(studentdata.substr(beginitem, enditem - beginitem));

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        int daysToComplete3 = stoi(studentdata.substr(beginitem, enditem - beginitem));

        beginitem = enditem + 1;
        enditem = studentdata.find(",", beginitem);
        string deg = studentdata.substr(beginitem, enditem - beginitem);

        Degree degree;
        if (deg == "SECURITY") { degree = SECURITY; }
        else if (deg == "NETWORK") { degree = NETWORK; }
        else if (deg == "SOFTWARE") { degree = SOFTWARE; }
        else{
            cerr << "DEGREE IS NOT RECOGNIZED. GOODBYE>\n";
            exit(-1);
        }

        add(studentID, firstName, lastName, email, age, daysToComplete1, daysToComplete2, daysToComplete3, degree);
    }
    else
    {
        cerr << "ERROR. LIST IS BIGGER THAN MAX SIZE. EXITING NOW";
        exit(-1);
    }
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, Degree degree)
{
    int daysToComplete[3];
    daysToComplete[0] = daysToComplete1;
    daysToComplete[1] = daysToComplete2;
    daysToComplete[2] = daysToComplete3;
    if (degree == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, email, age, daysToComplete, degree);
    if (degree == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, email, age, daysToComplete, degree);
    else if (degree == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, email, age, daysToComplete, degree);
    else classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, email, age, daysToComplete, degree);
}

void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++) this->classRosterArray[i]->print();
}

void Roster::printInvalidEmails() 
{
    cout << "Invalid email addresses: " << endl;
    bool valid = true;
    bool haveat = false;
    bool havedot = false;
    for (int i = 0; i <= lastIndex; i++)
    {

        string eMail = classRosterArray[i]->getEmail();
        for (int j = 0; j < eMail.size(); j++)
        {
            if (eMail[j] == ' ')
            {
                valid = false;
                break;
            }
            else if (eMail[j] == '@')
            {
                haveat = true;
            }
            else if (eMail[j] == '.')
                havedot = true;
        }
        if (!valid || !haveat || !havedot) 
            cout << classRosterArray[i]->getStudentID() << ": " << classRosterArray[i]->getEmail() << endl;
        valid = true; haveat = false; haveat = false;
    }
}

void Roster::printAveDaysInCourse(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {

        if (this->classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            int* days = classRosterArray[i]->getDaysToComplete();
            cout << "Student " << this->classRosterArray[i]->getStudentID() << ": " << (days[0] + days[1] + days[2]) / 3 << endl;
        }
    }
    if (!found) cout << "Student not found!" << endl;
}

void Roster::printByDegreeProgram(int d)
{
    cout << "These are the students in the " << degreeStrings[d] << " program:\n";
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
    }
}

void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) 
    {
        if (this->classRosterArray[i]->getStudentID() == studentID) 
        {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }

    }
    if (found) this->printAll();
    else cout << "ERROR. Student not found.";
}

Roster::~Roster()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete this->classRosterArray[i];

    }
    delete classRosterArray;
}


int main() {

    cout << "C 867 Scripting and Programming - Applications\n" << "Language: uC++\n" << "Student ID: 000616298\n" << "Garrison Smith\n\n";
    int numStudents = 5;

    const string studentData[] =
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Garrison,Smith,gsmi108@wgu.edu,36,14,17,21,SOFTWARE"
    };
    
    Roster* classRoster = new Roster(numStudents);

    for (int i = 0; i < numStudents; i++)
    {
        classRoster->parseThenAdd(studentData[i]); //parses student info, turns the info into a student object and adds that student to roster
    }

    cout << left << setw(5) << "ID";
    cout << left << setw(12) << "FIRST";
    cout << left << setw(15) << "LAST";
    cout << left << setw(25) << "EMAIL";
    cout << left << setw(8) << "AGE";
    cout << left << setw(21) << "DAYS IN COURSE";
    cout << left << setw(10) << "DEGREE" << endl;
    classRoster->printAll(); 
    cout << endl << endl;

    classRoster->printInvalidEmails();
    cout << endl;

    cout << "The average number of days for each student to complete a class: " << endl;
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->printAveDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
    }

    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);

    cout << endl <<"Remove A3:" << endl;

    classRoster->remove("A3");
  
    cout << endl << "Remove A3: " << endl;

    classRoster->remove("A3");

    classRoster->~Roster();
    return 0;
}

