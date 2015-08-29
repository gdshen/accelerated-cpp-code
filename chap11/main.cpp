#include <iostream>

#include "vec.h"
#include <vector>

using namespace std;
int *p;

int &test() {
    p = new int[6]{1, 2, 3, 4, 5, 6};
    cout << p[0] << " " << p[1] << "\n";
    cout << p << "\n";
    return p[0];
}

int main() {
    cout << "Hello, World!" << endl;
//    cout << test() << "\n";
    int &r = test();
    r = 3;
    cout << p[0] << "\n";

    vec<double> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(7);
    vector<double> e{1, 2, 3, 4, 5, 6};

    for(int i = 0; i < 6; i++) {
        cout << d[i] << "\n";
        cout << e[i] << "\n";
    }

}