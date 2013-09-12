#include "FTree.hpp"

FTree::FTree() {
    root = nullptr;
}

void
FTree::Insert(int n) {
    //std::shared_ptr<FNode> node(new Fnode(n));
    auto node = std::make_shared<FNode>(2);
    if(root == nullptr) {
        root = node;
    }
}

void FTree::deleteMin() {
	root = nullptr;

}
