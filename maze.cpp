/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <utility>

using namespace std;

const int MAX_HEIGHT = 100;
const int MAX_WIDTH = 100;

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
    int width;
    int height;
    vector<string> content;
    bool walls[MAX_HEIGHT][MAX_WIDTH];
    Coordinate start;
    Coordinate goal;

    void validate_file(string filename) {

    }
};


int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
    if (argc != 2) {
        cout << "Usage: ./maze.cpp maze.txt" << endl;
    }
    
    return 0;
}