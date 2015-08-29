#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>
#include <algorithm>

using namespace std;

char *duplicate_word(const char *p) {
    size_t length = strlen(p) + 1;
    char *new_array = new char[length];

    copy(p, p + length, new_array);

    return new_array;
}

int main(int argc, char **argv) {
//
//    for (int i = 0; i < argc; i++) {
//        cout << *(argv + i) << "\n";
//    }
//
//    cerr << "This is an error\n";
//    clog << "This is an log\n";
//
////    ifstream infile("/Users/shen/ClionProjects/Accelerated_CPP_Code/chapt10/data.dat");
//    ifstream infile("data.dat");
//    if (!infile) {
//        cerr << "This file is not existed\n";
//    }
//    ofstream outfile("/Users/shen/ClionProjects/Accelerated_CPP_Code/chapt10/out.dat");
//
//    string s;
//    while (getline(infile, s)) {
//        outfile << 1 << endl;
//        outfile << s << "\n";
//    }

    int *p = new int(42);
    cout << "pointer address " << p << "\n";
    delete p;
    cout << "pointer address " << p << "\n";
    cout << *p;
    return 0;
}