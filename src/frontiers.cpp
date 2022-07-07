#include "frontiers.h"

StackFrontier::StackFrontier() {};

void StackFrontier::add(std::shared_ptr<Node> n) 
{
    frontier.emplace_back(std::move(n));
}

bool StackFrontier::contains_state(Coordinate state) 
{
    int i;
    for (i = 0; i < frontier.size(); i++) {
        if (frontier[i]->state == state) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Node> StackFrontier::remove() 
{
    if (frontier.size() == 0) {
        throw std::underflow_error("empty frontier");
    }
    else {
        std::shared_ptr<Node> node = frontier.back();
        frontier.pop_back();
        return node;
    }
}

std::shared_ptr<Node> QueueFrontier::remove() 
{
    if (frontier.size() == 0) {
        throw std::underflow_error("empty frontier");
    }
    else {
        std::shared_ptr<Node> node = frontier.front();
        frontier.erase(frontier.begin());
        return node;
    }
}

