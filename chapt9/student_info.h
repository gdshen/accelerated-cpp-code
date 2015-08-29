//
// Created by Shen Guodong on 8/18/15.
//

#ifndef CHAPT9_STUDENT_INFO_H
#define CHAPT9_STUDENT_INFO_H

#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream &read(std::istream &);
    double grade() const;
};

#endif //CHAPT9_STUDENT_INFO_H
