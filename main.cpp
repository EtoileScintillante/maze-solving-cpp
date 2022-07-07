/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include "maze.h"
using namespace std;

int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
    if (argc != 3) {
        cout << "Usage: ./maze-solver path-to-maze bool" << endl;
    }

    // Set LIFO to true or false depending in given argument
    bool LIFO;
    if (strcasecmp(argv[2], "true") == 0) {LIFO = true;}
    if (strcasecmp(argv[2], "false") == 0) {LIFO = false;}

    // Ananlyze and solve the maze
    Maze m;
    m.validate_file(argv[1]);
    m.print();
    cout << "Solving..." << endl;
    cout << endl;
    m.solve(LIFO);
    m.print();
    cout << "States explored: " << m.num_explored << endl;

    return 0;
}