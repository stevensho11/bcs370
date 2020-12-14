#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Assignment {
int homeworkID, courseID, timeToComplete;
std::string completionStatus, description;

Assignment(int hwID, int ID, int t, std::string cs, std::string desc);

void display();
};