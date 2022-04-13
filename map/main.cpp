
#include <iostream>
#include "map.hpp"

bool MapColor(int country, map& world) {
    if (country >= world.numberOfCountries()) return true;

    bool aColorRemains = true;
    bool doneColoring = false;
    color c = red;

    while (aColorRemains && !doneColoring) {
        if (world.isValidColoring(country, c)) {
            world.colorCountry(country, c);
            doneColoring = MapColor(country + 1, world);
        }
        if ((++c) == none) aColorRemains = false;
    }
    if (!doneColoring) world.uncolorCountry(country); //back track
    return doneColoring;
}

int main() {

    // open a file and read into a map: not implemented

}