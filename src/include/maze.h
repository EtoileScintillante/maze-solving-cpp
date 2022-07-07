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
#include "frontiers.h"
#include <fstream>
#include <string.h>
#include <iostream>

class Maze {
public:
    Maze();
    int num_explored; // Explored states counter

    /**
     * @brief Checks if a given txt file is valid.
     * A txt file with a maze must contain an A (starting point) and a B (goal).
     * 
     * @param filename path to txt file.
     * @return true if valid, false otherwise.
     */
    bool validate_file(std::string filename);

    /// Prints the maze.
    void print();

    /**
     * @brief Tries to find a path from A to B.
     * 
     * @param LIFO true if LIFO is used (stack), false if FIFO is used (queue).
     */
    void solve(bool LIFO);
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

    /// Checks if a state is already explored.
    bool alreadyExplored(Coordinate State);

    /// Checks if a state is already in solution.
    bool inSolution(Coordinate State);
    
    /// Returns a vector containing the neighbor states of a given state.
    std::vector<Coordinate> neighbors(Coordinate state);
};

#endif /*__MAZE__*/