class Coordinate {
public:
    Coordinate() {x = 0; y = 0;}
    int x, y;
    Coordinate(int a, int b) { 
        x = a;
        b = y;
    }
    bool operator == (Coordinate c) {
        return x == c.x and y == c.y;
    }
    void print() {
        printf("(%i, %i)", x, y);
    }
};