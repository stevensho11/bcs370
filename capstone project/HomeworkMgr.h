#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "assignment.h"

class HomeworkMgr {
	std::vector<Assignment> assignments;
public:
	void addAssignment();
	Assignment* search(int n);
	void updateTime(int n, int updateTime);
	void updateCompletion(int n);
	void searchByTime(int t);
	void searchByCourse(int c);
	void displayInProgress();
	void displayUpTo(int n);
};