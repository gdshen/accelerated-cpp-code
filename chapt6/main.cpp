#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include "students_info.h"

using namespace std;

void back_inserter_test() {
    vector<int> x{1, 2, 3, 4, 5};
    vector<int> y{6, 7, 8, 9, 10};
    copy(x.begin(), x.end() - 1, back_inserter(y));
    for (auto &i : x)
        cout << i << " ";
    cout << endl;

    for (auto &i : y)
        cout << i << " ";
    cout << endl;

}

// using lamda function
bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}

vector<string> split(const string &str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), not_space);

        iter j = find_if(i, str.end(), space);
        ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

vector<string> split_with_lambda(const string &str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), [](char c) { return !isspace(c); });

        iter j = find_if(i, str.end(), [](char c) { return isspace(c); });
        ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

void vector_print(const vector<string> &v) {
    for (auto &x : v) {
        cout << x << "\n";
    }
}

bool is_palindrome(const string &str) {
    return equal(str.begin(), str.end(), str.rbegin());
}

// isalnum 判断是字母或者是数字
bool not_url_char(char c) {
    const static string url_char = "~;!?:@&$-_.+!*(),";
    return !(isalnum(c) || find(url_char.begin(), url_char.end(), c) != url_char.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    typedef string::const_iterator iter;

    iter i = b;
    while ((i = search(b, e, sep.begin(), sep.end())) != e) {
        if (i != b && i + sep.size() != e) {
            iter beg = i;
            while (beg != b && isalpha(beg[-1])) {
                beg--;
            }
            if (beg != i && not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        i += sep.size();
    }
    return e;
}


string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

vector<string> find_url(const string &s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    while (b != e) {
        b = url_beg(b, e);

        if (b != e) {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;
}

bool did_all_homework(const student_info &student) {
    return find(student.homework.begin(), student.homework.end(), 0) == student.homework.end();
}

istream& catogarized_student(istream& in) {
    vector<student_info> did, didnt;
    student_info s;
    while (read(in, s)) {
        if (did_all_homework(s)) {
            did.push_back(s);
        }
        else {
            didnt.push_back(s);
        }
    }

    if (did.empty()) {
        cout << "No students have done all their homework\n";
    }

    if (didnt.empty()) {
        cout << "No students have not done all their homework\n";
    }
    return in;
}

int main() {
    ios::sync_with_stdio(false);
    back_inserter_test();
    string line = "one two three four";
    vector_print(split(line));
    vector_print(split_with_lambda(line));

    cout << is_palindrome("eye") << " " << is_palindrome("eyee") << "\n";
    string text;
    vector_print(find_url(text));
    return 0;
}