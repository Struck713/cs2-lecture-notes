#ifndef CS2_ARRAY_H_
#define CS2_ARRAY_H_


/////////////////////////////////////
//Simple Dynamically Allocated Array
/////////////////////////////////////

#include <iostream>
#include <cassert>

//
// CLASS INV: ptr -> int[cap]
//

class Darray {
public:
            Darray();
            Darray(int);
            Darray(const Darray&); // Copy Constructor
            ~Darray();             // Destructor
    void    swap(Darray&);

    //Darray& operator=(const Darray&);
    Darray& operator=(Darray);
    int operator   [](int) const;
    int& operator  [](int);

    int capacity() const { return cap; }
    void resize (int);

private:
    int *ptr;
    int cap;
};

#endif