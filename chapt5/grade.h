//
// Created by Shen Guodong on 8/14/15.
//

#ifndef CHAPT4_GRADE_H
#define CHAPT4_GRADE_H
#include <vector>
#include "students_info.h"
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const student_info&);
#endif //CHAPT4_GRADE_H
