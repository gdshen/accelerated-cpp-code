//
// Created by Shen Guodong on 8/21/15.
//

#ifndef CHAPT13_CORE_H
#define CHAPT13_CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core {
public:
    friend class Students_info;

    Core() : midterm(0), final(0) { std::cout << "Calling the Core::Core();\n"; }

    Core(std::istream &is) { read(is); };

    std::string name() const;

    virtual std::istream &read(std::istream &);

    virtual double grade() const;

protected:
    std::istream &read_common(std::istream &);

    double midterm, final;
    std::vector<double> homework;

    virtual Core *clone() const { return new Core(*this); }

    virtual ~Core() { }

private:
    std::string n;
};

template<class T>
double grade(double, double, std::vector<T>) { return 0; }

template<class T>
std::istream &read_hw(std::istream &in, std::vector<T> &) { return in; }

bool compare(const Core &c1, const Core &c2) {
    return c1.name() < c2.name();
}

bool compare_grade(const Core &c1, const Core &c2) {
    return c1.grade() < c2.grade();
}

#endif //CHAPT13_CORE_H
