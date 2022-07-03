class Node {
public:
    Node() {state = Coordinate(); parent = NULL;}
    Coordinate state;
    std::shared_ptr<Node> parent;
    Node(Coordinate State, std::shared_ptr<Node> Parent) {
        state = State;
        parent = Parent;
    }
    void print() {
        printf("State of node: (%i, %i)\n", state.x, state.y);
    }
};