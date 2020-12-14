/*
* Stevens Ho
* BCS 370 - Capstone Project
* Use data structures and OOP to create a system that manages a college student's homework
* Main contains test code for the program
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "assignment.h"
#include "HomeworkMgr.h"

int main() {
	HomeworkMgr mgr;
	for (int i = 0; i < 6; i++)
	{
		mgr.addAssignment();
	}
	mgr.displayUpTo(6);
	std::cout << "---------------------------------------------------------------------\n";
	mgr.updateTime(1, 1);
	mgr.displayInProgress();
	std::cout << "---------------------------------------------------------------------\n";
	mgr.updateCompletion(6);
	mgr.updateCompletion(5);
	mgr.displayInProgress();
	std::cout << "---------------------------------------------------------------------\n";
	mgr.searchByTime(3);
	std::cout << "---------------------------------------------------------------------\n";
	mgr.searchByCourse(950144);
	std::cout << "---------------------------------------------------------------------\n";

}

