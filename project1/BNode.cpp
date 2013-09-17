#include "BNode.hpp"

BNode::BNode() {

}

BNode::BNode(int key, int priority) : key(key), n(priority), right(nullptr), left(nullptr), parent(nullptr) {

}
