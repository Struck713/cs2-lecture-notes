
#include <iostream>
#include "map.hpp"

map::map() {
    for (int i = 0; i < MAP_SIZE; ++i) {
        coloring[i] = none;
        for (int j = 0; j < MAP_SIZE; ++j) neighbor[i][j] = false;
    }
}

// PRE: none
// POST: Retval TRUE if no adjacent country is the same color
bool map::isValidColoring(int country, color c) const {
    for (int i = 0; i < numOfCountries; ++i)
        if (neighbor[country][i] && (c == coloring[i])) return false;
    return true;
}