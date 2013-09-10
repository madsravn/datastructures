#ifndef FTREE_HPP_
#define FTREE_HPP_

#include "FNode.hpp"

class FTree {
    public:
        FTree();
        void Insert(int n);
        std::shared_ptr<FNode> root;

};

#endif
