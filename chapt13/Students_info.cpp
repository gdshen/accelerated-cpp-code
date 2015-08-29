//
// Created by Shen Guodong on 8/22/15.
//

#include "Students_info.h"
#include "Grad.h"

std::istream &Students_info::read(std::istream &is) {
    delete cp;

    char ch;
    is >> ch;
    if (ch == 'U') {
        cp = new Core(is);
    }
    else {
        cp = new Grad(is);
    };

    return is;
}

Students_info::Students_info(const Students_info &info) : cp(0) {
        if (info.cp) {
            cp = info.cp->clone();
        }
}

Students_info &Students_info::operator=(const Students_info &info) {
    if (&info != this) {
        delete cp;
        if (info.cp) {
            cp = info.cp->clone();
        }
        else {
            cp = 0;
        }
        return *this;
    }
}
