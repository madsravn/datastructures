#include "BNode.hpp"

BNode::BNode() {

}

BNode::BNode(int tkey, int priority) :key(tkey), prio(priority),right(nullptr), left(nullptr), parent(nullptr) {

}
