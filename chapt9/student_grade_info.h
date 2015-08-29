//
// Created by Shen Guodong on 8/18/15.
//

#ifndef CHAPT9_STUDENT_GRADE_INFO_H
#define CHAPT9_STUDENT_GRADE_INFO_H

#include <string>
#include <vector>
#include <istream>

class student_grade_info {
private:
    std::string name;
    double midterm, final;
    std::vector<double> homework;

public:


//    student_grade_info(const std::string &name, double midterm, double final, const std::vector<double> &homework)
//            : name(name), midterm(midterm), final(final), homework(homework) { }
    student_grade_info():midterm(0), final(0){}
    student_grade_info(std::istream &);

    double grade() const;
    std::istream &read(std::istream &);
    std::string getname() const;
    bool valid() const {return !homework.empty()};

};


#endif //CHAPT9_STUDENT_GRADE_INFO_H
