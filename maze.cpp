/* Program to solve txt based mazes.
Where A is the starting point and B the goal */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Node {
    pair<int, int> state;
    Node* parent;
    pair<int, int> action;
};