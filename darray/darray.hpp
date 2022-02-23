#ifndef CS2_ARRAY_H_
#define CS2_ARRAY_H_

#include <iostream>
#include <cassert>

class Darray {
public:
    Darray();
    Darray(int);
    Darray(const Darray&); // copy ctor
    ~Darray();             // destructor
    
    void swap(Darray&);
    Darray& operator=(const Darray&) const;
    Darray& operator=(Darray) const;

    int operator[](int) const;
    int& operator[](int);
    int capacity() const;
    void resize(int);

private:
    int* ptr;
    int cap;

}

#endif