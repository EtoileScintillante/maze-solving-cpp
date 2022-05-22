//#include "coordinate.h"
#include <stdio.h>

class Node {
public:
    Node() {state = Coordinate(); parent = NULL;}
    Coordinate state;
    Node* parent;
    Node(Coordinate State, Node* Parent) {
        state = State;
        parent = Parent;
    }
    void print() {
        printf("State of node: (%i, %i)\n", state.x, state.y);
    }
};