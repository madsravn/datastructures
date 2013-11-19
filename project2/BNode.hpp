#ifndef BNODE_HPP_
#define BNODE_HPP_
#include "INode.hpp"
#include <memory>

class BNode : public INode {
    public:
        BNode(int tkey, int priority);
        BNode();
        std::shared_ptr<BNode> left, right, parent;
        //int key;
        int prio;

};

#endif
