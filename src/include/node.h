/*                                  
 * node.h
 *
 * Created on: 6 July 2022
 * Author: EtoileScintillante
 */

#ifndef __NODE__
#define __NODE__

#include "coordinate.h"
#include <memory>

class Node {
public:
    Coordinate state;
    std::shared_ptr<Node> parent;
    Node();
    Node(Coordinate State, std::shared_ptr<Node> Parent);
};

#endif /*__NODE__*/