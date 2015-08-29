//
// Created by Shen Guodong on 8/14/15.
//

#include "students_info.h"

using std::vector;
using std::istream;

bool compare(const student_info &s1, const student_info &s2) {
    return s1.name < s2.name;
}

istream &read_hw(istream &in, vector<double> &hw) {
    if (in) {
        hw.clear();

        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;

}


istream &read(istream &is, student_info &s) {
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}