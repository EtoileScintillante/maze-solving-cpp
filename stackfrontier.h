#include <stdexcept>

using namespace std;

class StackFrontier {
public:
    vector<Node> frontier;

    StackFrontier() {}

    // Add node to end of frontier
    void add(Node n) {
        frontier.push_back(n);
    }

    // Check if a given state already exists in the frontier
    bool contains_state(Coordinate state) {
        int i;
        for (i = 0; i < frontier.size(); i++) {
            if (frontier[i].state.x == state.x && frontier[i].state.y == state.y) {
                return true;
            }
        }
        return false;
    }

    // Remove node from end of frontier
    Node remove() {
        if (frontier.empty()) {
            throw std::underflow_error("empty frontier");
        }
        else {
            Node node = frontier.back();
            frontier.pop_back();
            return node;
        }
    }
};