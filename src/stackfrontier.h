#include <stdexcept>
#include <memory>

class StackFrontier {
public:
    std::vector<std::shared_ptr<Node> > frontier;

    StackFrontier() {}

    // Add node to end of frontier
    void add(std::shared_ptr<Node> n) {
        frontier.emplace_back(std::move(n));
    }

    // Check if a given state already exists in the frontier
    bool contains_state(Coordinate state) {
        int i;
        for (i = 0; i < frontier.size(); i++) {
            if (frontier[i]->state == state) {
                return true;
            }
        }
        return false;
    }

    // Remove node from end of frontier
    std::shared_ptr<Node> remove() {
        if (frontier.size() == 0) {
            throw std::underflow_error("empty frontier");
        }
        else {
            std::shared_ptr<Node> node = frontier.back();
            frontier.pop_back();
            return node;
        }
    }
};