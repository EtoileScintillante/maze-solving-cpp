/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include "maze.h"
using namespace std;

int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
   if (argc != 2) {
        cout << "Usage: ./maze-solver path-to-maze" << endl;
    }

    Maze m;
    m.validate_file(argv[1]);
    m.print();
    cout << "Solving..." << endl;
    cout << endl;
    m.solve();
    m.print();
    cout << "States explored: " << m.num_explored << endl;

    return 0;
}