
#include <iostream>

enum poleName { left, middle, right };

class pole {
public:
    pole() {};
    pole(poleName np) : p(np) {};

    friend std::ostream& operator<<(std::ostream& out, pole rhs) {
        switch (rhs.p) {
            case right: out << "right";
            case left: out << "left";
            case middle: out << "middle";
        }
    }

private:
    poleName p;
};

// PRE: n > 0
// POST: print out moves required to solve towers of hanoi problem
void move(int n, pole src, pole temp, pole dest) {
    if (n == 1) 
        std::cout << "move one disk from " << src << " to " << dest << std::endl;
    else {
        move(n - 1, src, dest, temp);
        std::cout << "move one disk from " << src << " to " << dest << std::endl;
        move(n - 1, temp, src, dest);
    }
}
