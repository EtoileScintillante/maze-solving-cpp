/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

using namespace std;

const int MAX_HEIGHT = 100;
const int MAX_WIDTH = 100;

struct Coordinate {
public:
  int x, y;
  Coordinate(int a, int b) { this->x = a; this->y = b; }
};

class Node {
public:
    Coordinate state = Coordinate(0,0);
    Node* parent;
    Node(Coordinate State, Node* Parent) {
        state = State;
        parent = Parent;
    }
};

class StackFrontier {
public:
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
public:
    string filename;
    int width;
    int height;
    int num_explored;
    bool walls[MAX_HEIGHT][MAX_WIDTH];
    bool solved;
    Coordinate start = Coordinate(0,0);
    Coordinate goal = Coordinate(0,0);
    vector<Coordinate> explored;
    vector<Coordinate> solution;
    Maze(string fileName) {
        filename = fileName;
    }

    bool validate_file() {
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

    // Check if a state is already explored
    bool alreadyExplored(Coordinate State) {
        int i;
        for (i = 0; i < explored.size(); i++) {
            if (State.x == explored[i].x && State.y == explored[i].y) {
                return true;
            }
        }
        return false;
    }

    // Check if a state is already in solution
    bool inSolution(Coordinate State) {
    int i;
        for (i = 0; i < solution.size(); i++) {
            if (State.x == solution[i].x && State.y == solution[i].y) {
                return true;
            }
        }
        return false;
    }
    // Prints the maze
    void print() {
        int i, j;

        for (i = 0; i < height; i++) {

            for (j = 0; j < width; j++) {

                Coordinate temp = Coordinate(i, j);
                if (walls[i][j] == true) {
                    cout << "█";
                }
                else if (temp.x == start.x && temp.y == start.y) {
                        cout << "A";
                }
                else if (temp.x == goal.x && temp.y == goal.y) {
                    cout << "B";
                }
                else if (solved == true && inSolution(temp) == true) {
                    cout << "*";
                }
                else {
                    cout << " ";
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
        Node startPos = Node(start, NULL);
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


int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
    if (argc != 2) {
        cout << "Usage: ./maze maze.txt" << endl;
    }

    string filename = argv[1];
    Maze m = Maze("maze1.txt");
    m.print();
    cout << "Solving..." << endl;
    m.solve();
    m.print();
    cout << "Stated explored: " << m.num_explored << endl;
}