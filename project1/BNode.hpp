#ifndef BNODE_HPP_
#define BNODE_HPP_

#include <memory>

class BNode {
    public:
        BNode(int number);
        BNode();
    private:
        int n;
        std::shared_ptr<BNode> left, right;
};

#endif
