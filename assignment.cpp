#include "assignment.h"



//a student can have multiple assignments from one course, so homeworkID will be the key
int homeworkID, courseID, timeToComplete;
std::string completionStatus, description;

//default constructor
Assignment::Assignment(int hwID = 0, int ID = 0, int t = 0, std::string cs = "Incomplete", std::string desc = "hw") {
	this->homeworkID = hwID;
	this->courseID = ID;
	this->timeToComplete = t;
	this->completionStatus = cs;
	this->description = desc;
}

//display member variables for Assignment
void Assignment::display() {
	std::cout << "Homework ID: " << homeworkID << "\n";
	std::cout << "Course ID: " << courseID << "\n";
	std::cout << "Description: " << description << "\n";
	std::cout << "Due in: " << timeToComplete << " days" << "\n";
	std::cout << "Completion status: " << completionStatus << "\n";
	std::cout << "---------------------------------------------------------------------\n";
}