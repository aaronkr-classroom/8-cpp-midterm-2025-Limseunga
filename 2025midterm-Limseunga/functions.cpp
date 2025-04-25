// functions.cpp
#include "functions.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cctype>

bool isNumber(const std::string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return !s.empty();
}

double calculateAverage(const std::vector<int>& scores) {
    int total = 0;
    for (int score : scores) total += score;
    return scores.empty() ? 0.0 : static_cast<double>(total) / scores.size();
}

void sortByName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
        });
}

void printResults(const std::vector<Student>& students) {
    std::cout << "\n--- ���� ��� ---\n";
    for (const auto& s : students) {
        std::cout << "�̸�: " << s.name
            << " | ��� ����: " << std::fixed << std::setprecision(2) << s.average << "\n";
    }
}