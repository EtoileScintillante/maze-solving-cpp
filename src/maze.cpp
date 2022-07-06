#include "maze.h"

Maze::Maze() {};

bool Maze::validate_file(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    int AB_counter = 0;
    int lineCounter = 0; // Height
    int charCounter = 0; // Width
    std::string line;

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

    // If file does not contain A or B, return false
    if (AB_counter != 2) {
        return false;
    }

    // Set height and width
    height = lineCounter;
    width = charCounter / lineCounter;

    // Iterate over every line and store walls as bools in array
    // True if the char is wall, else false
    std::string temp;
    std::vector<bool> v;
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

bool Maze::alreadyExplored(Coordinate State)
{
    int i;
    for (i = 0; i < explored.size(); i++) {
         if (State == explored[i]) {
            return true;
        }
    }
    return false;
}

bool Maze::inSolution(Coordinate State) 
{
    int i;
    for (i = 0; i < solution.size(); i++) {
        if (State == solution[i]) {
            return true;
        }
    }
    return false;
}

void Maze::print() 
{
    for (int a = 0; a < height; a++) 
    {
        for (int b = 0; b < width; b++) 
        {
            if (walls[a][b] == true) {
                std::cout << "█";
            }
            if (walls[a][b] == false) {
                Coordinate temp;
                temp.x = a;
                temp.y = b;
                if (temp == startpos) {
                    std::cout << "A";
                }
                else if (temp == goal) {
                    std::cout << "B";
                }
                else if (solved == true && inSolution(temp) == true) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                    
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<Coordinate> Maze::neighbors(Coordinate state)
{
    std::vector<Coordinate> v;
    int x = state.x;
    int y = state.y;

    // Up neighbor
    Coordinate up;
    up.x = x - 1;
    up.y = y;
    if (up.x >= 0 && walls[up.x][up.y] != true) {
        v.push_back(up);
    }

    // Down neighbor
    Coordinate down;
    down.x = x + 1;
    down.y = y;
    if (down.x < height && walls[down.x][down.y] != true) {
        v.push_back(down);
    }

    // Left neighbor
    Coordinate left;
    left.x = x;
    left.y = y - 1;
    if (left.y >= 0 && walls[left.x][left.y] != true) {
        v.push_back(left);
    }

    // Right neighbor
    Coordinate right;
    right.x = x;
    right.y = y + 1;
    if (right.y < width & walls[right.x][right.y] != true) {
        v.push_back(right);
    }

    return v;
}

void Maze::solve()
{
    // Keep track of number of states explored
    num_explored = 0;

    // Initialize frontier to just the starting position
    std::shared_ptr<Node> startPos(new Node(startpos, NULL));
    StackFrontier ST;
    ST.add(move(startPos));

    // Keep looping until solution is found
    while (true)
    {
        // If nothing left in frontier, then no path
        if (ST.frontier.size() == 0) {
            std::cout << "No path found" << std::endl;
            return;
        }

        // Pop a node from the frontier
        std::shared_ptr<Node> node = ST.remove();
        num_explored++;

        // If node is the goal, then we have a solution
        if (node->state == goal) {              
            solved = true;
            solution.push_back(node->state);
            std::shared_ptr<Node> temp = node->parent;
            while (temp != NULL) 
            {
                solution.push_back(temp->state);
                temp = temp->parent; 
            }
            return;
        }

        // Mark state as explored
        explored.push_back(node->state);

        // Add neighbors to frontier
        std::vector<Coordinate> n = neighbors(node->state);
        int i;
        for (i = 0; i < n.size(); i++) 
        {
            if (ST.contains_state(n[i]) == false && alreadyExplored(n[i]) == false) {
                std::shared_ptr<Node> child(new Node(n[i], node));
                ST.add(child);
            }
        }
    }
}