# Maze Solving

## About
Inspired by [one](https://www.youtube.com/watch?v=qzhEB8FxxRs) of the lectures from the online course [CS50AI](https://cs50.harvard.edu/ai/2020/). The professor showed a python program to solve mazes from a txt file and I wanted to recreate that same program in c++. 

## Example
```
./maze-solver mazes/maze3.txt false
██    █
██ ██ █
█B █  █
█ ██ ██
     ██
A██████

Solving...

██    █
██ ██ █
█B █  █
█*██ ██
**   ██
A██████

States explored: 6
```
## Compile
```
cmake . && make
```
## Run
```
./maze-solver path-to-maze bool
```
## How it works
The program takes as input a text file with a maze and analyses it. It finds the walls, paths, starting point and goal.
* 'A' = starting point
* 'B' = goal
* ' ' = path
* '#' = wall

(Examples can be found in this repo)  
Once the analyzing is done, the program tries to find a path from A to B using [Depth-first search](https://nl.wikipedia.org/wiki/Depth-first_search) (DFS) or [Breadth-first search](https://nl.wikipedia.org/wiki/Breadth-first_search) (BFS). It starts by initializing an empty frontier (vector of nodes) and adds the starting point node to the frontier. A node has two attributes: a state (x and y coordinates) and a pointer to a parent node. Then it enters an infinite loop in which the following happens:
1. Pop node from the frontier (LIFO or FIFO mechanism).
2. Check if state of node is goal.
3. If state is goal, loop through all the parent nodes (starting at the parent of the node with the goal state) and add the states of the parents to a vector (this vector basically contains all the states that form the path from A to B).
4. If state is not goal, add state to a vector (this vector keeps track of already explored states) and add neighbors of state to the frontier (each state of a node can have up to 4 neighbors: up, down, left and right).
5. Go back to step 1.

The program exits the loop when it reaches the goal or when the frontier is empty (in which case there is no path found).

To use LIFO (the stack), pass in true as 3rd command line argument. For FIFO (the queue) pass in false. They sometimes lead to different paths. 

One thing to note though is that DFS and BFS are both uninformed search algorithms and these types of algorithms are often inefficient in terms of time and/or memory.  
