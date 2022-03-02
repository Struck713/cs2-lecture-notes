
#include <iostream>
#include <cassert>

// factorial function
int nfact(int n) {
    if (n <= 1) return 1;
    return n * nfact(n - 1);
}

// fibbonachi sequence function
int fib(int n) {
    if (n <= 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

// int main() {

//     int fact5 = nfact(5);
//     assert(fact5 == 120);
//     std::cout << "5! == 120";

//     return 0;
// }
