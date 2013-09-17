#ifndef BNODE_HPP_
#define BNODE_HPP_

#include <memory>

class BNode {
    public:
        BNode(int tkey, int priority);
        BNode();
        std::shared_ptr<BNode> left, right, parent;
        int key, prio;

};

#endif
