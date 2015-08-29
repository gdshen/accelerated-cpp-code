//
// Created by Shen Guodong on 8/24/15.
//

#ifndef CHATP14_REF_HANDLE_H
#define CHATP14_REF_HANDLE_H


#include <stddef.h>
#include <stdexcept>

template<class T>
class Ref_handle {

public:
    Ref_handle() : refptr(new size_t(1)), p(0) { }

    Ref_handle(T *t) : refptr(new size_t(1)), p(t) { }

    Ref_handle(const Ref_handle &h) : refptr(h.refptr), p(h.p) {
        ++*refptr;
    }

    Ref_handle &operator=(const Ref_handle &h) {
        ++*h.refptr;
        if (--*refptr == 0) {
            delete refptr;
            delete p;
        }

        refptr = h.refptr;
        p = h.p;
        return *this;
    }

    ~Ref_handle() {
        if (--*refptr) {
            delete refptr;
            delete p;
        }
    };

    operator bool() const {return p;}

    T &operator*() const {
        if (p) {
            return *p;
        }
        else {
            throw std::runtime_error("unbound Ref_handle");
        }
    }

    T *operator->() const {
        if (p) {
            return p;
        }
        else {
            throw std::runtime_error("unbound Ref_handle");
        }
    }
private:
    T *p;
    size_t *refptr;
};


#endif //CHATP14_REF_HANDLE_H
