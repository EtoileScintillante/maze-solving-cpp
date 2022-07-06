#include "coordinate.h"

Coordinate::Coordinate() {x = 0; y = 0;}

Coordinate::Coordinate(int a, int b)
{
    x = a;
    b = y;
}

bool Coordinate::operator== (Coordinate c)
{
    return x == c.x and y == c.y;
}