//
// Created by Shen Guodong on 8/21/15.
//

#ifndef CHAP12_STR_H
#define CHAP12_STR_H

#include <vector>
#include <algorithm>
#include <iostream>

class str {
    friend std::istream &operator>>(std::istream &, str &);

public:
    typedef std::vector<char>::size_type size_type;


    str() { } //default constructor

    str(size_type n, char c) : data(n, c) { }

    str(char *p) {
        std::copy(p, p + strlen(p), std::back_inserter(data));
        std::cout << "you are calling the initial constructor\n";
    }

    template<class in>
    str(in b, in e) {
        std::copy(b, e, std::back_inserter(data));
    }

    str(const str &val) {
        data = val.data;
        std::cout << "call the copy constructor\n";
    }

    str &operator=(const str &val) {
        data = val.data;
        std::cout << "call the assignment constuctor\n";
        return *this;
    }

    size_type size() const {
        return data.size();
    }

    char &operator[](size_type i) {
        return data[i];
    }

    const char &operator[](size_type i) const {
        return data[i];
    }

    str &operator+=(const str &s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }




//private:
public:
    std::vector<char> data;
};

std::istream &operator>>(std::istream &in, str &s) {
    s.data.clear();
    char c;
    while (in.get(c) && isspace(c)) {
        // just loop
    }

    if (in) {
        do {
            s.data.push_back(c);
        } while (in.get(c) && isspace(c));
    }

    if (in) {
        in.unget();
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const str &s) {
    for (int i = 0; i < s.size(); i++) {
        out << s[i];
    }
    return out;
}

str operator+(const str &s1, const str &s2) {
    str r = s1;
    r += s2;
    return r;
}

#endif //CHAP12_STR_H
