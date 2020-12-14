#include "HomeworkMgr.h"


//user is asked to choose the homework file he wants to add data from to system
void HomeworkMgr::addAssignment() {
	int tmpHWID, tmpID, tmpT;
	std::string inputName, compStatus, desc;
	std::cout << "Please specify the file name of the assignment you want to add" << "\n";
	std::cin >> inputName;
	std::fstream inFile(inputName, std::ios::in);

	if (inFile) {
		//homework files are formatted as: homeworkID first, courseID second, timeToComplete third, completionStatus fourth, and description fifth
		inFile >> tmpHWID >> tmpID >> tmpT >> compStatus >> desc;
		Assignment newAssignment(tmpHWID, tmpID, tmpT, compStatus, desc);
		assignments.push_back(newAssignment);
	}
	else {
		std::cout << "Error on file open\n";
	}

}
//search method that returns pointer to an object in the vector of assignments to be used in update methods
Assignment* HomeworkMgr::search(int n) {
	for (Assignment& a : assignments) {
		if (a.homeworkID == n) {
			return &a;
		}
	}
	return nullptr;
}
//updates timeToComplete in assignment with homeworkID n
void HomeworkMgr::updateTime(int n, int updateTime) {
	this->search(n)->timeToComplete = updateTime;
}
//updates completionStatus in assignment with homeworkID n
void HomeworkMgr::updateCompletion(int n) {
	this->search(n)->completionStatus = "Complete";
}
//search and display all Incomplete assignments that are due within t days
void HomeworkMgr::searchByTime(int t) {
	for (Assignment a : assignments) {
		if (a.timeToComplete <= t && a.completionStatus != "Complete") {
			a.display();
		}
	}
}
//search and display all assignments by course
void HomeworkMgr::searchByCourse(int c) {
	for (Assignment a : assignments) {
		if (a.courseID == c) {
			a.display();
		}
	}
}
//display all assignments that are not Complete
void HomeworkMgr::displayInProgress() {
	for (Assignment a : assignments) {
		if (a.completionStatus != "Complete") {
			a.display();
		}
	}
}
//display all Incomplete assignments up to specified number
void HomeworkMgr::displayUpTo(int n) {
	if (n == 0) {
		return;
	}
	n--;
	if (assignments[n].completionStatus != "Complete") {
		assignments[n].display();
	}
	displayUpTo(n);
}