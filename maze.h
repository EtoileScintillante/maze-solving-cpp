#include <vector>
#include "coordinate.h"
#include "node.h"
#include "stackfrontier.h"
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

class Maze {
public:
     Maze() {}
    int width;
    int height;
    int num_explored;
    bool solved;
    Coordinate startpos;
    Coordinate goal;
    vector<string> content;
    vector<Coordinate> explored;
    vector<Coordinate> solution;
    vector<vector<bool> > walls;

    bool validate_file(string filename) {
        ifstream file;
        file.open(filename);
        int AB_counter = 0;
        int lineCounter = 0; // Height
        int charCounter = 0; // Width
        string line;

        // File must contain an A and B
        while (getline(file, line)) {
            int k;
            content.push_back(line); // Add every line to vector content
            for (k = 0; k < line.length(); k++) {
                charCounter++;
                if (line[k] == 'A') {
                    AB_counter++;
                    startpos.x = lineCounter;
                    startpos.y = k;
                } 
                if (line[k] == 'B') {
                    AB_counter++;
                    goal.x = lineCounter;
                    goal.y = k;
                }
            }
            lineCounter++;
        }

        goal.print();
        startpos.print();

        // If file does not contain A or B, return false
        if (AB_counter != 2) {
            return false;
        }

        // Set height and width
        height = lineCounter;
        width = charCounter / lineCounter;

        // Iterate over every line and store walls as bools in array
        // True if the char is wall, else false
        string temp;
        vector<bool> v;
        for (int a = 0; a < height; a++) {
            temp = content[a];
            for (int b = 0; b < width; b++) {
                if (temp[b] == '#') {
                    v.push_back(true);
                }
                else {
                    v.push_back(false);
                }  
            }
            walls.push_back(v);
            v.clear();
        }

        return true;
    }

    // Check if a state is already explored
    bool alreadyExplored(Coordinate State) {
        int i;
        for (i = 0; i < explored.size(); i++) {
            if (State == explored[i]) {
                return true;
            }
        }
        return false;
    }

    // Check if a state is already in solution
    bool inSolution(Coordinate State) {
    int i;
        for (i = 0; i < solution.size(); i++) {
            if (State == solution[i]) {
                return true;
            }
        }
        return false;
    }

    // Prints the maze
    void print() {
        for (int a = 0; a < height; a++) {
            for (int b = 0; b < width; b++) {

                if (walls[a][b] == true) {
                    cout << "█";
                }
                if (walls[a][b] == false) {
                    Coordinate temp;
                    temp.x = a;
                    temp.y = b;
                    if (temp == startpos) {
                        cout << "A";
                    }
                    else if (temp == goal) {
                        cout << "B";
                    }
                    else if (solved == true && inSolution(temp) == true) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
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
        
        // Keep track of number of states explored
        num_explored = 0;

        // Initialize frontier to just the starting position
        Node startPos = Node(startpos, NULL);
        StackFrontier frontier = StackFrontier();
        frontier.add(startPos);

        // Keep looping until solution is found
        while (true) {
            
            // If nothing left in frontier, then no path
            if (frontier.frontier.size() == 0) {
                throw std::underflow_error("empty frontier");
            }

            // Nhoose a node from the frontier
            Node node = frontier.remove();
            num_explored++;

            // If node is the goal, then we have a solution
            if (node.state.x == goal.x && node.state.y == goal.y) {
                solved = true;
                while (node.parent != NULL) {
                    solution.push_back(node.state);
                    Node* temp;
                    temp = node.parent;
                    node = *temp;
                }
            }

            // Mark state as explored
            explored.push_back(node.state);

            // Add neighbors to frontier
            vector<Coordinate> n = neighbors(node.state);
            int i;
            for (i = 0; i < n.size(); i++) {
                if (frontier.contains_state(n[i]) == false && alreadyExplored(node.state) == false) {
                    Node child = Node(n[i], &node);
                    frontier.add(child);
                }
            }
        }
    }
};