#include <iostream>
#include "str.h"

using namespace std;

class real_number {
public:
    double a;

    real_number() { }

    real_number(double a) : a(a) { }

    real_number(const real_number &r) {
        a = r.a;
        cout << "call the real_nubmer copy constructor\n";
    }
};

class complex_number {
public:
    double real_part;
    double virtual_part;


    complex_number() { }

    complex_number(const real_number &number) {
        real_part = number.a;
        virtual_part = 0;
        cout << "automatic transformaiton\n";
    }

    complex_number &operator=(const complex_number &val) {
        real_part = val.real_part;
        virtual_part = val.virtual_part;
        cout << "call the assignment constructor\n";
    }
};


int main() {
    str hello = "world";
    str world = hello;
    world = hello;
    str test = world;
    str less(test);

    cout << string(100, '-') << "\n";
    //test auto conversations
    real_number a;
    complex_number c;
    c = a; //
    return 0;
}