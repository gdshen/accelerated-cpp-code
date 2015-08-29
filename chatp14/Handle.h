//
// Created by Shen Guodong on 8/24/15.
//

#ifndef CHATP14_HANDLE_H
#define CHATP14_HANDLE_H

#include <stdexcept>

template<class T>
class Handle {
public:
    Handle() : p(0) { }

    Handle(const Handle &s) : p(0) { if (s.p) p = s.p->clone; }

    Handle &operator=(const Handle &);

    Handle(T *t) : p(t) { };

    ~Handle() { delete p; }

    operator bool() const { return p; }

    T &operator*() const;
    T *operator->() const;

private:
    T *p;
};


#endif //CHATP14_HANDLE_H

template<class T>
Handle<T> &Handle<T>::operator=(const Handle &rhs) {
    if (&rhs != this) {
        delete p;
        p = rhs.p ? rhs.p->clone : 0;
    }
    return *this;
}

template<class T>
T &Handle::operator*() const {
    if (p) {
        return *p;
    }
    else {
        throw std::runtime_error("unbound handle");
    }
}

template<class T>
T *Handle::operator->() const {
    if (p) {
        return p;
    }
    else {
        throw std::runtime_error("unbound handle");
    }
}
