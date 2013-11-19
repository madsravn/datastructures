#include "BNode.hpp"

BNode::BNode() {

}

BNode::BNode(int tkey, int priority) : prio(priority),right(nullptr), left(nullptr), parent(nullptr) {
    key = tkey;

}
