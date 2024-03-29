# Maletic CS2 Lecture

This repo is a collection of all of the code I have copied down during [J. Maletic](http://www.cs.kent.edu/~jmaletic/ "J. Maletic's website")'s lectures at [KSU](https://www.kent.edu/cs "Kent State University").
All of the code is written in C++. There also could possibly be a *Makefile* or two added at some point. **I have no clue.**

## Projects
- stack: A basic stack ADT
- set: A basic set ADT
- string: A basic string ADT (not dynamic)
- darray: A dynamically allocated array
- darray_generic: A generic dynamically allocated array
- queue: A basic queue ADT implemented as a circular array
- linkedlist: A linked list ADT that trades off some memory for some computation time
    - stack: A linked list stack
    - queue: A linked list circular queue
    - dlist: A dually linked list
- tree
    - binary search tree: A tree where each node has 2 children
- recursion: Examples of recursive solutions to factorials, the fibbonachi sequence and the Towers of Hanoi
- map: A backtracking algorithm to solve the 4 Color Theorem
- inheritance: An example of inheritance using virtual methods
    - shape: Basic shape class that is inherited by a triangle, circle and rectangle class.
    - format: A word processor that has different formatting options that inherit from a formal class.

## Compiling
To build any of the projects in here, we use [clang++](https://clang.llvm.org/ "clang++ website"). Clone the repo and run this command:
```terminal
clang++ <somefile> <some other file> <a third file>
```

Clang++ will compile and link all of the files, along with any of the standard library files required.

## License
I do not have a license for this. This is lecture code. Do what you will with it.
