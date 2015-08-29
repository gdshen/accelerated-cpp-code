/*
 * compute students grade
 */
#include <iostream>
#include <ios>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main() {
    cout << "Please input your name ";
    string name;
    cin >> name;
    cout << "Hello " + name + "!\n";

    cout << "Please input your midterm and final examination score: ";
    double midterm;
    double final;
    cin >> midterm >> final;

    cout << "Please input your homework grades, followed by eof \n";

    vector<double> homework;
    double x = 0;

    while (cin >> x) {
        homework.push_back(x);
    }

    typedef  vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0) {
        cout << "your must input your homwork grade" << endl;
        return -1;
    }

    sort(homework.begin(),homework.end());

    vec_sz mid = size/2;
    double midian = size % 2 == 0 ? (homework[mid-1] + homework[mid])/2 : homework[mid];

    /*
     * The type std::streamsize is a signed integral type
     * used to represent the number of characters transferred in an I/O operation or the size of an I/O buffer.
     * It is used as a signed counterpart of std::size_t, similar to the POSIX type ssize_t.
     */
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * midian
    << endl;
    setprecision(prec);
    cout << "hello world" <<endl;
    return 0;
}