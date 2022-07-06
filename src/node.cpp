#include "node.h"

Node::Node() {state = Coordinate(); parent = NULL;}

Node::Node(Coordinate State, std::shared_ptr<Node> Parent) 
{
    state = State;
    parent = Parent;
}