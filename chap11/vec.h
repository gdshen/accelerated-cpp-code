//
// Created by Shen Guodong on 8/19/15.
//

/*
 * to learn abstract data class, we define vector ourselves.
 * functions are:
 * 1. contain data
 * 2. contain data size
 * 3. automatic grow size when data container is full
 * 4. offer iterator to access data element
 * optional
 * 5. [] based indexed
 * 6. we want to support the generic programming
 * important tips
 * 1. class initial
 * 2. class copy
 * 3. class assignment
 * 4. class destroy
 *
 * questions:
 * 1. what is the difference between class assignment and class copy
 * 区别在于原先有无元素
 * 模板类的定义和实现不能分离
 */
#ifndef CHAP11_VEC_H
#define CHAP11_VEC_H

#include <cstddef>
#include <memory>
#include <algorithm>

template<class T>
class vec {
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;

    void create();

    void create(iterator, iterator);

    void create(size_type, const T &);

    void uncreate() {

        if (data) {
            iterator it = avail;
            while (it != data) {
                alloc.destroy(--it);
            }
            alloc.deallocate(data, limit - data);
        }
        data = avail = limit = 0;
    }

    void grow() {
        size_type new_size = 2 * (limit - data) > 1 ? 2 * (limit -data) : 1;
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);
        uncreate();

        data = new_data;
        avail = new_avail;
        limit = data + new_size;
    }

    void uncheck_append(const T &t) {
        alloc.construct(avail++, t);
    }

public:


    vec() { create(); };

    vec(size_t n, const T &val = T()) { create(n, val); };

    vec(const vec &v) { create(v.begin(), v.end()); } // copy constructor
    size_type size() const { return data - limit; }

    ~vec() { uncreate(); }

    T &operator[](size_type i) { return data[i]; }

    const T &operator[](size_type i) const { return data[i]; }

    vec &operator=(const vec &rhs) {
        if (&rhs != this) {
            uncreate();
            create(rhs.begin(), rhs.end());
        }
        return *this;
    }

    void push_back(const T &val) {
        if (avail == limit) {
            grow();
        }
        uncheck_append(val);

    }

    iterator begin() { return data; }

    const_iterator begin() const { return data; }

    iterator end() { return limit; }

    const_iterator end() const { return limit; }


};

template<class T>
void vec<T>::create() {
    data = avail = limit = 0;
}

template<class T>
void vec<T>::create(vec::size_type n, const T &val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template<class T>
void vec<T>::create(vec::iterator i, vec::iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

#endif //CHAP11_VEC_H
