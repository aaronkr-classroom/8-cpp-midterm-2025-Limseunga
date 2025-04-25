// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "functions.h"

int main() {
    int studentCount = 5;
    std::vector<Student> students;

    std::cout << "학생 수를 입력하세요 (기본값 5): ";
    std::string input;
    std::getline(std::cin, input);
    if (!input.empty() && isNumber(input)) {
        studentCount = std::stoi(input);
    }

    for (int i = 0; i < studentCount; ++i) {
        Student s;
        std::cout << "\n학생 " << i + 1 << " 이름: ";
        std::getline(std::cin, s.name);

        std::cout << "5개의 과제 점수를 입력하세요 (띄어쓰기로 구분): ";
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string token;
        s.scores.clear();

        while (iss >> token) {
            if (!isNumber(token)) {
                std::cout << "숫자만 입력하세요. 다시 입력.\n";
                --i;
                break;
            }
            s.scores.push_back(std::stoi(token));
            if (s.scores.size() == 5) break;
        }

        if (s.scores.size() != 5) {
            std::cout << "정확히 5개의 점수를 입력해야 합니다.\n";
            --i;
            continue;
        }

        s.average = calculateAverage(s.scores);
        students.push_back(s);
    }

    sortByName(students);
    printResults(students);

    return 0;
}