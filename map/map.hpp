#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>

const int MAP_SIZE = 10;
enum colorRange { red, blue, green, yellow, none };

class color {
public:
    color() : c(none) {};
    color(colorRange x) : c(x) {};
    bool operator==(color x) { return x.c == c; };
    color& operator++() { c = colorRange(c+1); return *this; }

    friend std::ostream& operator<<(std::ostream&, color);

private:
    colorRange c;
};

class map {
public:
    map();
    int numberOfCountries() const { return numOfCountries; };
    bool isValidColoring(int, color) const;
    void colorCountry(int n, color c) { coloring[n] = c; };
    void uncolorCountry(int n) { colorCountry(n, none); };

    friend std::ostream& operator<<(std::ostream&, const map&);
    friend std::ostream& operator<<(std::ostream&, map);

private:
    int numOfCountries;
    bool neighbor[MAP_SIZE][MAP_SIZE];
    color coloring[MAP_SIZE];
};

#endif