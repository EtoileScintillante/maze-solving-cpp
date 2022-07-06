# Maze Solving

## About
Inspired by [one](https://www.youtube.com/watch?v=qzhEB8FxxRs) of the lectures from the online course [CS50AI](https://cs50.harvard.edu/ai/2020/). The professor showed a python program to solve mazes (txt based) and I wanted to recreate that same program in c++. 

## Example
```
./maze-solver mazes/maze4.txt
████████████████████████
█        ██            █
A  ███   ██  ████████  █
██████   ██        ██  █
█            ████  ██  B
████████     ████  ██  █
██    ████         ██  █
██  ████     ████  ██  █
██                 ██  █
█████  ███████   ████  █
█████  ███████   ████  █
██       ██      ████  █
████████████████████████

Solving...

████████████████████████
█ *******██ ***********█
A**███  *██ *████████ *█
██████  *██ *      ██ *█
█       *****████  ██ *B
████████     ████  ██  █
██    ████         ██  █
██  ████     ████  ██  █
██                 ██  █
█████  ███████   ████  █
█████  ███████   ████  █
██       ██      ████  █
████████████████████████

States explored: 134
```
## Compile
```
cmake . && make
```
## Run
```
./maze-solver path-to-maze
```
## How it works
The program takes as input a text file with a maze and analyses it. It finds the walls, paths, starting point and goal.
* 'A' = starting point
* 'B' = goal
* ' ' = path
* '#' = wall

(Examples can be found in this repo)  
Once the analyzing is done, the program tries to find a path from A to B using [Depth-first search](https://nl.wikipedia.org/wiki/Depth-first_search) (DFS). It starts by initializing an empty frontier (vector of nodes) and adds the starting point node to the frontier. A node has two attributes: a state (x and y coordinates) and a pointer to a parent node. Then it enters an infinite loop in which the following happens:
1. Pop node from the frontier (LIFO mechanism).
2. Check if state of node is goal.
3. If state is goal, loop through all the parent nodes (starting at the parent of the node with the goal state) and add the states of the parents to a vector (this vector basically contains all the states that form the path from A to B).
4. If state is not goal, add state to a vector (this vector keeps track of already explored states) and add neighbors of node to the frontier (each node can have up to 4 neighbors: up, down, left and right).
5. Go back to step 1.

The program exits the loop when it reaches the goal or when the frontier is empty (in which case there is no path found).

One thing to note though is that this way of solving, using DFS, is not very fast. 
