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

    bool validate_file(string filename) {
        ifstream file;
        file.open(filename);
        int AB_counter = 0;
        int lineCounter = 0; // Height
        int charCounter = 0; // Width
        string line;

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