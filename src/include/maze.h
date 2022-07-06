/*                                  
 * maze.h
 *
 * Created on: 6 July 2022
 * Author: EtoileScintillante
 * 
 * A maze has the following contents:
 * '#' = walls
 * ' ' = path
 * 'A' = starting point
 * 'B' = goal
 */

#ifndef __MAZE__
#define __MAZE__

#include <vector>
#include "stackfrontier.h"
#include <fstream>
#include <string.h>
#include <iostream>

class Maze {
public:
    Maze();
    int num_explored; // Explored states counter
private:
    int width;
    int height;
    bool solved;
    Coordinate startpos; // The position of letter A in txt file
    Coordinate goal; // The position of letter B in txt file
    std::vector<std::string> content; // Contains content of txt file (every string is one line of the file)
    std::vector<Coordinate> explored; // Contains all the explored states
    std::vector<Coordinate> solution; // Contains the states that lead us from A to B
    std::vector<std::vector<bool> > walls; // true if wall, false otherwise
public:
    // Check if txt file is valid (it must contain an A and B)
    bool validate_file(std::string filename);
private:
    // Check if a state is already explored
    bool alreadyExplored(Coordinate State);

    // Check if a state is already in solution
    bool inSolution(Coordinate State);
public:
    // Prints the maze
    void print();
private:
    // Every node has a state and every state has 4 possible neighbor states (up, down, left and right)
    // This function returns a vector containing the neighbors of a state
    std::vector<Coordinate> neighbors(Coordinate state);
public:
    // Try to find path from A to B
    void solve();
};

#endif /*__MAZE__*/