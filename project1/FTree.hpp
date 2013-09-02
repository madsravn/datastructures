#ifndef FTREE_HPP_
#define FTREE_HPP_

#include "FNode.hpp"

class FTree {
    public:
        FTree();

    private:
        std::unique_ptr<FNode> root;

};

#endif
