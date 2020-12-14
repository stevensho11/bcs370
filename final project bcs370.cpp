/*
* Stevens Ho
* BCS 370 - Capstone Project
* Use data structures and OOP to create a system that manages a college student's homework
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct Assignment {
	//a student can have multiple assignments from one course, so homeworkID will be the key
	int homeworkID, courseID, timeToComplete;
	std::string completionStatus, description;

	//default constructor
	Assignment(int hwID = 0, int ID = 0, int t = 0, std::string cs = "Incomplete", std::string desc = "hw") {
		this->homeworkID = hwID;
		this->courseID = ID;
		this->timeToComplete = t;
		this->completionStatus = cs;
		this->description = desc;
	}

	//display member variables for Assignment
	void display() {
		std::cout << "Homework ID: " << homeworkID << "\n";
		std::cout << "Course ID: " << courseID << "\n";
		std::cout << "Description: " << description << "\n";
		std::cout << "Due in: " << timeToComplete << " days" << "\n";
		std::cout << "Completion status: " << completionStatus << "\n";
		std::cout << "---------------------------------------------------------------------\n";
	}
};

class HomeworkMgr {
	std::vector<Assignment> assignments;
public:
	//user is asked to choose the homework file he wants to add data from to system
	void addAssignment() {
		int tmpHWID, tmpID, tmpT;
		std::string inputName, compStatus, desc;
		std::cout << "Please specify the file name of the assignment you want to add" << "\n";
		std::cin >> inputName;
		std::fstream inFile(inputName, std::ios::in);

		if (inFile) {
			//homework files are organized as: homeworkID first, courseID second, timeToComplete third, completionStatus fourth, and description fifth
			inFile >> tmpHWID >> tmpID >> tmpT >> compStatus >> desc;
			Assignment newAssignment(tmpHWID, tmpID, tmpT, compStatus, desc);
			assignments.push_back(newAssignment);
		}
		else {
			std::cout << "Error on file open\n";
		}

	}
	//search method that returns pointer to an object in the vector of assignments to be used in update methods
	Assignment *search(int n) {
		for (Assignment& a : assignments) {
			if (a.homeworkID == n) {
				return &a;
			}
		}
		return nullptr;
	}
	//updates timeToComplete in assignment with homeworkID n
	void updateTime(int n, int updateTime) {
		this->search(n)->timeToComplete = updateTime;
	}
	//updates completionStatus in assignment with homeworkID n
	void updateCompletion(int n) {
		this->search(n)->completionStatus = "Complete";
	}
	//search and display all Incomplete assignments that are due within t days
	void searchByTime(int t) {
		for (Assignment a : assignments) {
			if (a.timeToComplete <= t && a.completionStatus != "Complete") {
				a.display();
			}
		}
	}
	//search and display all assignments by course
	void searchByCourse(int c) {
		for (Assignment a : assignments) {
			if (a.courseID == c) {
				a.display();
			}
		}
	}
	//display all assignments that are not Complete
	void displayInProgress() {
		for (Assignment a : assignments) {
			if (a.completionStatus != "Complete") {
				a.display();
			}
		}
	}
	//display all Incomplete assignments up to specified number(back to front - not specified index)
	void displayUpTo(int n) {
		if (n == 0) {
			return;
		}
		if (assignments[n].completionStatus != "Complete") {
			assignments[n].display();
		}
		n--;
		displayUpTo(n);
	}
};




int main()
{
}


