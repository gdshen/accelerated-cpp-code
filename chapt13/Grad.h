//
// Created by Shen Guodong on 8/21/15.
//

#ifndef CHAPT13_GRAD_H
#define CHAPT13_GRAD_H

#include "Core.h"

class Grad : public Core {
public:
    Grad() : Core(), thesis() { std::cout << "Calling the Grad::Grad()\n"; }

    Grad(std::istream &is) { read(is); };

    double grade() const;

    std::istream &read(std::istream &);

protected:
    Grad *clone() const { return new Grad(*this); }

private:
    double thesis;
};


#endif //CHAPT13_GRAD_H
