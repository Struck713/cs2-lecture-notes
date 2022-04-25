
#ifndef CS2_SHAPE_INH_
#define CS2_SHAPE_INH_

#include <iostream>

class shape { // abstract class
public:
    shape() : x(0), y(0) {};
    virtual ~shape() {}
    void move(int nx, int ny) { x = nx; y = ny; };
    virtual void draw() = 0; // pure virtual method

    virtual bool isRectangle() const = 0;
    virtual bool isSquare() const = 0;
    virtual bool isCircle() const = 0;
    virtual bool isTriangle() const = 0;


protected:
    int x, y;
};

class rectangle : public shape {
public:
    rectangle() : shape(), h(0), w(0) {};
    rectangle(int nh, int nw) : rectangle(), h(nh), w(nw) {};
    virtual void draw() { std::cout << "Rectangle at " << x << ", " << y << std::endl; };

    virtual bool isRectangle() { return true; };

protected:
    int h, w;
};

class square : public rectangle {
public:
    square() : rectangle() {};
    square(int nh) : rectangle(nh, nh) {};
    virtual void draw() { std::cout << "Square at " << x << ", " << y << std::endl; };

    virtual bool isRectangle() { return true; };
    virtual bool isSquare() { return true; };
};

class circle : public shape {
public:
    circle() : shape(), r(0) {};
    circle(int nr) : circle(), r(nr) {};
    virtual void draw() { std::cout << "Circle at " << x << ", " << y << std::endl; };

    virtual bool isCircle() { return true; };

protected:
    int r;
};

class triangle : public shape {
public:
    triangle() : shape(), b(0), h(0) {};
    triangle(int nb, int nh) : triangle(), b(nb), h(nh) {};
    virtual void draw() { std::cout << "Triangle at " << x << ", " << y << std::endl; };

protected:
    int b, h;
};

#endif