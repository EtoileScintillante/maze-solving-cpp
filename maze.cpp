/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>

using namespace std;

struct Coordinate {
  int x, y;
  Coordinate(int a, int b) { this->x = a; this->y = b; }
};

class Node {
    Coordinate state;
    Node* parent;
};

class StackFrontier {
    deque<Node> frontier;
    StackFrontier() {frontier;}

    void add(Node n) {
        frontier.push_back(n);
    }

    Coordinate contains_state(Coordinate state) {
        //TODO
    }

    Node remove() {
        if (frontier.empty()) {
            throw std::underflow_error("empty frontier");
        }
        else {
            Node node = frontier.back();
            frontier.pop_back();
            return node;
        }
    }
};

class Maze {
    //TODO
};