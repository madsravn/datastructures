#include "BHeap.hpp"

BHeap::BHeap() : size(0), root(nullptr) {
}

void 
BHeap::MakeHeap() {
    //Kode her
}

void
BHeap::sayName() {
    std::cout << "I am BHeap" << std::endl;
}

std::string 
nodeInfo(std::shared_ptr<BNode> n) {
    if(n->left == nullptr && n->right == nullptr) {
        return ""; 
    }
    std::string temp = "";
    if(n->left != nullptr) {
        temp = temp + std::to_string(n->n) + " -> " + std::to_string( n->left->n) + "\n";
        temp = temp + nodeInfo(n->left);
    }
    if(n->right != nullptr) {
        temp = temp + std::to_string(n->n) + " -> " + std::to_string( n->right->n) + "\n";

        temp = temp + nodeInfo(n->right);
    }
    return temp;
}

std::string
BHeap::graph() {
    return  "digraph G {\n\n" + nodeInfo(root) + "\n}";
}

int
BHeap::FindMin() {
	if(root == nullptr)
		return -1;
	else
		return root->key;
}

void
BHeap::Insert(int k, int priority) {
    if(size == 0) {
        auto node = std::make_shared<BNode>(k, priority);
        root = node;
    } else {
        std::string s = std::bitset<64> (size+1).to_string();
        size_t pos = 0;
        while(pos < s.size() && s.at(pos) == '0') {
            pos++;
        }
        pos++;
        std::shared_ptr<BNode> node = root;
        while(pos < s.size()-1) {
            if(s.at(pos) == '0') {
                node = node->left;
            }
            if(s.at(pos) == '1') {
                node = node->right;
            }
            pos++;
        }
        auto newnode = std::make_shared<BNode>(i);
        if(s.at(pos) == '0') {
            node->left = newnode;
        }
        if(s.at(pos) == '1') {
            node->right = newnode;
        }
        newnode->parent = node;
        while(newnode->parent != nullptr) {
            if(newnode->n < newnode->parent->n) {
                int temp = newnode->n;
                newnode->n = newnode->parent->n;
                newnode->parent->n = temp;
                //std::cout << newnode->n << " bytter plads med " << newnode->parent->n << std::endl;
            }
            newnode = newnode->parent;
        }

    }
    size++;
}

void
BHeap::DeleteMin() {

}

void 
BHeap::DecreaseKey(int k, int i) {



}
