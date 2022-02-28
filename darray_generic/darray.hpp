#ifndef CS2_ARRAY_GENERIC_H_
#define CS2_ARRAY_GENERIC_H_

//
// A template version of our dynamically allocated array
//

#include <iostream>
#include <cassert>

//
// CLASS INV: ptr->T[cap]
// REQUIRES: assignable(T) && copyConstructable(T) && destructable(T)
//
template <typename T>
class Darray {
public:
    Darray() : ptr(0), cap(0) {};
    Darray(int);
    Darray(const Darray<T>&);
    ~Darray() { delete [] ptr; };

    void swap(Darray<T>&);

    Darray<T>& operator=(Darray<T> rhs) { swap(rhs); return *this; }
    T operator[](int i) const { return ptr[i]; }
    T& operator[](int i) { return ptr[i]; }
    int capacity() const { return cap; }
    void resize(int);

private:
    T *ptr;
    int cap;
};

// REQUIRES: n>= 0
template <typename T>
Darray<T>::Darray(int n) : Darray<T>() {
    if (n <= 0) return;
    cap = n;
    ptr = new T[cap];
}

template <typename T>
Darray<T>::Darray(const Darray<T>& actual) {
    cap = actual.cap;
    ptr = new T[cap];
    for (int i = 0; i < cap; ++i) 
        ptr[i] = actual.ptr[i];
}


// constant time swap
template <typename T>
void Darray<T>::swap(Darray<T>& rhs) {
    T* temp = ptr;
    ptr = rhs.ptr;
    rhs.ptr = temp;

    int tempCap = cap;
    cap = rhs.cap;
    rhs.cap = cap; 
}

template <typename T>
void Darray<T>::resize(int n) {
    int smaller = cap;
    if (n < smaller) smaller = n;

    cap = n;
    T* temp = new T[cap];

    for (int i = 0; i < smaller; ++i)
        temp[i] = ptr[i];

    delete [] ptr;
    ptr = temp;
}

#endif