/*                                  
 * stackfrontier.h
 *
 * Created on: 6 July 2022
 * Author: EtoileScintillante
 */

#ifndef __STACKFRONTIER__
#define __STACKFRONTIER__

#include <stdexcept>
#include <vector>
#include <memory>
#include "node.h"

class StackFrontier {
public:
    std::vector<std::shared_ptr<Node> > frontier;

    StackFrontier();

    /// Adds node to end of frontier.
    void add(std::shared_ptr<Node> n);

    /// Checks if a given state already exists in the frontier.
    bool contains_state(Coordinate state);

    /// Removes node from end of frontier.
    std::shared_ptr<Node> remove();
};

#endif /*__STACKFRONTIER__*/