//
// Created by Shen Guodong on 8/22/15.
//

#ifndef CHAPT13_STUDENTS_INFO_H
#define CHAPT13_STUDENTS_INFO_H


#include "Core.h"
#include <istream>
#include <string>

class Students_info {
public:
    Students_info() : cp(0) { }

    Students_info(std::istream &is) : cp(0) { read(is); }

    Students_info(const Students_info &);

    Students_info &operator=(const Students_info &);

    ~Students_info() { delete cp; }

    std::istream &read(std::istream &);

    std::string name() const {
        if (cp) {
            return cp->name();
        }
        else {
            throw std::runtime_error("Uninitialized student");
        }
    }

    double grade() const {
        if (cp) {
            return cp->grade();
        }
        else {
            throw std::runtime_error("Uninitialized student");
        }
    }

    static bool compare(const Students_info &s1, const Students_info &s2) {
        return s1.name() < s2.name();
    }

private:
    Core *cp;
};


#endif //CHAPT13_STUDENTS_INFO_H
