/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

const int MAX_HEIGHT = 100;
const int MAX_WIDTH = 100;

struct Coordinate {
  int x, y;
  Coordinate(int a, int b) { this->x = a; this->y = b; }
};

class Node {
public:
    Coordinate state;
    Node* parent;
};

class StackFrontier {
    deque<Node> frontier;

    // Add node to end of frontier
    void add(Node n) {
        frontier.push_back(n);
    }

    // Check if a given state already exists in the frontier
    bool contains_state(Coordinate state) {
        int i;
        for (i = 0; i < frontier.size(); i++) {
            if (frontier[i].state.x == state.x && frontier[i].state.y == state.y) {
                return true;
            }
        }
        return false;
    }

    // Remove node from end of frontier
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
    bool walls[MAX_HEIGHT][MAX_WIDTH];
    bool solved;
    Coordinate start;
    Coordinate goal;

    bool validate_file(string filename) {
        ifstream file;
        file.open(filename);
        int AB_counter = 0;
        int lineCounter = 0; // Height
        int charCounter = 0; // Width
        string line;
        vector<string> content;

        // File must contain an A and B
        while (getline(file, line)) {
            int i;
            content.push_back(line); // Add every line to vector content
            for (i = 0; i < line.length(); i++) {
                charCounter++;
                if (line[i] == 'A' || line[i] == 'B') {
                    AB_counter++;
                }
            }
            lineCounter++;
        }

        // If file does not contain A or B, return false
        if (AB_counter != 2) {
            return false;
        }

        // Set height and width
        height = lineCounter;
        width = charCounter / lineCounter;

        // Iterate over every line and store walls as bools in array
        // True if the char is wall, else false
        int i, j;
        string temp;
        for (i = 0; i < height; i++) {
            temp = content[i];
            for (j = 0; j < width; j++) {
                if (content[i][j] == '#') {
                    walls[i][j] = true;
                }
                else if (content[i][j] == 'A') {
                    start = Coordinate(i, j);
                    walls[i][j] = false;
                }
                else if (content[i][j] == 'B') {
                    goal = Coordinate(i, j);
                    walls[i][j] = false;
                }
                else if (content[i][j] == ' ') {
                    walls[i][j] = false;
                }
                else {
                    walls[i][j] = false;
                }
            }
        }

        return true;
    }

    // Prints the maze
    void print() {
        //TODO
    }

    // Every node has 4 possible neighbor states (up, down, left  and right)
    // This function returns a pointer to an array with neighbors
    vector<Coordinate> neighbors(Coordinate state) {
        vector<Coordinate> v;;

        // Up neighbor
        Coordinate up = Coordinate(state.x - 1, state.y);
        if (up.x >= 0) {
            v.push_back(up);
        }

        // Down neighbor
        Coordinate down = Coordinate(state.x + 1, state.y);
        if (down.x < height) {
            v.push_back(down);
        }

        // Left neighbor
        Coordinate left = Coordinate(state.x, state.y - 1);
        if (left.y >= 0) {
            v.push_back(left);
        }

        // Right neighbor
        Coordinate right = Coordinate(state.x, state.y + 1);
        if (right.y < width) {
            v.push_back(right);
        }

        return v;
    }

    // Try to find path from A to B
    void solve() {
        //TODO
    }
};


int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
    if (argc != 2) {
        cout << "Usage: ./maze maze.txt" << endl;
    }

    ifstream file;
    file.open("maze1.txt");
    vector<string> temp;
    string line;
    while (getline(file, line)) {
        temp.push_back(line);
    }
    
    cout << temp[4] << endl;

    return 0;
}