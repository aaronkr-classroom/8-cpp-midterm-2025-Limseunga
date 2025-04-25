// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> scores;
    double average;
};

bool isNumber(const std::string& s);
double calculateAverage(const std::vector<int>& scores);
void sortByName(std::vector<Student>& students);
void printResults(const std::vector<Student>& students);

#endif