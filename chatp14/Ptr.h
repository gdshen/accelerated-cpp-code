//
// Created by Shen Guodong on 8/24/15.
//

#ifndef CHATP14_PTR_H
#define CHATP14_PTR_H

#include <stddef.h>

template<class T>
class Ptr {
public:
    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p->clone() : 0;
        }

    }

private:
    T *p;
    size_t *refptr;
};


#endif //CHATP14_PTR_H
