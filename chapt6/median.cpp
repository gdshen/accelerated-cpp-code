//
// Created by Shen Guodong on 8/14/15.
//
#include "median.h"
using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> vec) {
    typedef vector<double>::size_type vz;
    vz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }
    sort(vec.begin(), vec.end());
    vz mid = size / 2;
    return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}

