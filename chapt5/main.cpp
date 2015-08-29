#include <iostream>
#include <string>
#include <list>
#include "students_info.h"
#include "grade.h"
#include <cctype>

using namespace std;

bool fgrade(const student_info &s) {
    return grade(s) < 60;
}

// inial version
//vector<student_info> extract_fails(vector<student_info> &students) {
//    vector<student_info> fail, pass;
//    for (vector<student_info>::size_type i = 0; i < students.size(); i++) {
//        if (fgrade(students[i])) {
//            fail.push_back(students[i]);
//        }
//        else {
//            pass.push_back(students[i]);
//        }
//    }
//    students = pass;
//    return fail;
//}

// second version
//vector<student_info> extract_fails(vector<student_info> &students) {
//    vector<student_info> fail;
//    for (vector<student_info>::size_type i = 0; i < students.size(); i++) {
//        if (fgrade(students[i])) {
//            fail.push_back(students[i]);
//            students.erase(students.begin() + i);
//        }
//        else{
//            i++;
//        }
//        return fail;
//    }
//}

//third version using iterator
//vector<student_info> extract_fails(vector<student_info> &students) {
//    vector<student_info> fail;
//    for (vector<student_info>::iterator iter = students.begin(); iter != students.end(); iter++) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        }
//        else {
//            iter++;
//        }
//    }
//    return fail;
//}

// fourth version optimization for remove data
list<student_info> extract_fails(list<student_info> &students) {
    list<student_info> fail;
    list<student_info>::iterator iter = students.begin();
    while (iter != students.end()) {
        if (grade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else {
            iter++;
        }
    }
    return fail;
}

vector<string> split(const string &s) {
    vector<string> ret;
    string::size_type i, j;
    i = 0;
    while (i != s.size()) {
        while (i != s.size() && isspace(s[i])) {
            i++;
        }

        j = i;
        while (j != s.size() && !isspace(s[j])) {
            j++;
        }

        if (i != j) {
            ret.push_back(string(s.substr(i, j - i)));
            i = j;
        }
    }
    return ret;
}

int main() {
    string s;
    cout << "Please input a line\n";

    getline(cin, s);
    auto v = split(s);
//    for (vector<string>::size_type i = 0; i < v.size(); i++) {
//        cout << v[i] << endl;
//    }
    for (auto &i : v) {
        cout << i << endl;
    }
}