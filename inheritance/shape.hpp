
#ifndef CS2_SHAPE_INH_
#define CS2_SHAPE_INH_

#include <iostream>

class shape {
public:
    shape() : x(0), y(0) {};
    void move(int nx, int ny) { x = nx; y = ny; };
    virtual void draw() { std::cout << "Shape at " << x << ", " << y << std::endl; };
protected:
    int x, y;
};

class rectangle : public shape {
public:
    rectangle() : shape(), h(0), w(0) {};
    rectangle(int nh, int nw) : rectangle(), h(nh), w(nw) {};
    virtual void draw() { std::cout << "Rectangle at " << x << ", " << y << std::endl; };

protected:
    int h, w;
}

class square : public rectangle {
public:
    rectangle() : rectangle() {};
    rectangle(int nh) : rectangle(nh, nh) {};
    virtual void draw() { std::cout << "Square at " << x << ", " << y << std::endl; };
}

class circle : public shape {
public:
    circle() : shape(), r(0) {};
    circle(int nr) : circle(), r(nr) {};
    virtual void draw() { std::cout << "Circle at " << x << ", " << y << std::endl; };

protected:
    int r;
}

class triangle : public shape {
public:
    triangle() : shape(), b(0), h(0) {};
    triangle(int nb, int nh) : triangle(), b(nb), h(nh) {};
    virtual void draw() { std::cout << "Triangle at " << x << ", " << y << std::endl; };

protected:
    int b, h;
}

#endif