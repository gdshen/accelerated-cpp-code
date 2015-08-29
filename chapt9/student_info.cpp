//
// Created by Shen Guodong on 8/18/15.
//

#include "student_info.h"

std::istream &Student_info::read(std::istream &in) {
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}
