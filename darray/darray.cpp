
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

Darray::~Darray() {
    delete [] ptr;
}