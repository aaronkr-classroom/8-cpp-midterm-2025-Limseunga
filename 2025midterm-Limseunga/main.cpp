// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "functions.h"

int main() {
    int studentCount = 5;
    std::vector<Student> students;

    std::cout << "�л� ���� �Է��ϼ��� (�⺻�� 5): ";
    std::string input;
    std::getline(std::cin, input);
    if (!input.empty() && isNumber(input)) {
        studentCount = std::stoi(input);
    }

    for (int i = 0; i < studentCount; ++i) {
        Student s;
        std::cout << "\n�л� " << i + 1 << " �̸�: ";
        std::getline(std::cin, s.name);

        std::cout << "5���� ���� ������ �Է��ϼ��� (����� ����): ";
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string token;
        s.scores.clear();

        while (iss >> token) {
            if (!isNumber(token)) {
                std::cout << "���ڸ� �Է��ϼ���. �ٽ� �Է�.\n";
                --i;
                break;
            }
            s.scores.push_back(std::stoi(token));
            if (s.scores.size() == 5) break;
        }

        if (s.scores.size() != 5) {
            std::cout << "��Ȯ�� 5���� ������ �Է��ؾ� �մϴ�.\n";
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