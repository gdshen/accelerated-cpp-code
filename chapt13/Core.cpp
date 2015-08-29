//
// Created by Shen Guodong on 8/21/15.
//

#include "Core.h"

std::string Core::name() const {
    return n;
}

double Core::grade() const {
    return ::grade(midterm, final, homework);
}

std::istream &Core::read_common(std::istream &in) {
    in >> n >> midterm >> final;
    return in;
}

std::istream &Core::read(std::istream &in) {
    read_common(in);
    ::read_hw(in, homework);
    return in;
}
