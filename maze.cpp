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

    // File must contain an A and B
    bool validate_file(string filename) {
        ifstream file;
        file.open(filename);
        int AB_counter = 0;
        int lineCounter = 0; // Height
        int charCounter = 0; // Width
        string line;

        while (getline(file, line)) {
            int i;
            for (i = 0; i < line.length(); i++) {
                charCounter++;
                if (line[i] == 'A' || line[i] == 'B') {
                    AB_counter++;
                }
            }
            lineCounter++;
        }

        if (AB_counter == 2) {
            height = lineCounter;
            width = charCounter / lineCounter;
            return true;
        }

        return false;
    }
};


int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
    if (argc != 2) {
        cout << "Usage: ./maze.cpp maze.txt" << endl;
    }

    ifstream file;
    file.open("maze1.txt");
    string line;
    while (getline(file, line)) {
        //test
    }
    
    return 0;
}