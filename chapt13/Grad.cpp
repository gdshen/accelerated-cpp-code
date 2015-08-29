//
// Created by Shen Guodong on 8/21/15.
//

#include "Grad.h"
#include <algorithm>

std::istream &Grad::read(std::istream &in) {
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const {
    return std::min(Core::grade(), thesis);
}
