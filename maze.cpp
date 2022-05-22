/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include "maze.h"
using namespace std;

int main(int argc, char* argv[]) {

    // Check if correct number of arguments is provided
   if (argc != 2) {
        cout << "Usage: ./maze maze.txt" << endl;
    }
    
    Node n(Coordinate(2, 3), nullptr);
    cout << n.state.x << endl;

    Maze m;
    m.validate_file("maze1.txt");
    cout << m.walls[0][3] << endl;
}