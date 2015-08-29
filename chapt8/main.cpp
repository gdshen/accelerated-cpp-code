/*
 * writing generic functions
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
T median(vector<T> v) {
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0) {
        throw domain_error("median can not be calculated on empty data set");
    }

    sort(begin(v), end(v));


    return size % 2 == 0 ? (v[size / 2 - 1] + v[size / 2]) / 2 : v[size / 2];
}

template<class T>
T add(T a, T b) {
    return a + b;
}

template<class Out>
void split(const string &str, Out os) {
    typedef string::const_iterator iter;
    iter i = begin(str);
    while (i != end(str)) {
        i = find_if(i, end(str), [](char c){return !isspace(c);});

        iter j = find_if(i, end(str), [](char c){return isspace(c);});
        if (i != j) {
            *os++ = string(i, j);
            i = j;
        }
    }
    return;
}
int main() {
    vector<double> d{1.2, 2.6};
    vector<int> i{3, 7};

    cout << median(d) << " " << median(i) << "\n";
    string a = "hello";
    string b = "world";
    cout << add(1, 2) << " " << add(a, b) << "\n";
    cout << max(3.8, 3.6) << "\n";

    int c[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << c << "\n";
    cout << begin(c) << "\n";
    for (const auto &i : c){
        cout <<i << " " << &i << "\n";

    }
    return 0;
}