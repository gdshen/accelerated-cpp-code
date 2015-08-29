//
// Created by Shen Guodong on 8/14/15.
//

#ifndef CHAPT4_STUDENTS_INFO_H
#define CHAPT4_STUDENTS_INFO_H
#include <iostream>
#include <string>
#include <vector>

struct student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const student_info&, const student_info&);
std::istream& read(std::istream&, student_info&);
std::istream& read_hw(std::istream&, std::vector<student_info>&);
#endif //CHAPT4_STUDENTS_INFO_H
