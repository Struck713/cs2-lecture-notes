//
// Simple dynamically allocated array
//


#include "darray.hpp"
#include <cstdlib>

Darray::Darray() {
    cap = 0;
    ptr = 0;
}

// REQUIRES: 0 <= n
Darray::Darray(int n) {
    if (n < 0) n = 0;
    cap = n;
    ptr = new int[cap];
}

// Can NOT call exit() - no assert()
// Would infinitely call eachother
Darray::~Darray() {
    delete [] ptr;
}

// Must be passed by reference or would result in infinite loop
Darray::Darray(const Darray& actual) {  // copy ctor
    cap = actual.cap;
    ptr = new int[cap];

    for (int i = 0; i < cap; ++i) {
        ptr[i] = actual.ptr[i];
    }
}

// Similar to the copy constructer but we had to do some simple cleanup.
// Old fashioned way - sortof

/*Darray& Darray::operator= (const Darray& rhs) {
    if (ptr != rhs.ptr) {
        delete [] ptr;
        cap = rhs.cap;
        ptr = new int[cap];
        for (int i = 0; i < cap; ++i) {
            ptr[i] = rhs.ptr[i];
        }
    }
    return *this;
}
*/

// New way, one or the other.
Darray& Darray::operator= (Darray rhs) {
    swap(rhs); 
    return *this;
}

// Constant time swap - no matter how big the array is.
void Darray::swap(Darray& rhs) {
    int* temp = ptr;
    ptr = rhs.ptr;
    rhs.ptr = temp;

    int tcap = cap;
    cap = rhs.cap;
    rhs.cap = tcap;
}

int Darray::operator[](int i) const {
    assert(i >= 0 && i < cap);
    return ptr[i];
}

int& Darray::operator[](int i) {
    assert(i >= 0 && i < cap);
    return ptr[i];
}

void Darray::resize(int newCap) {
    int smaller = newCap;
    if (cap < newCap) smaller = cap;

    int* temp = new int[newCap];
    for (int i = 0; i < smaller; ++i)
        temp[i] = ptr[i];

    delete [] ptr;
    ptr = temp;
} 