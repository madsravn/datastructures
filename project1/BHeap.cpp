#include "BHeap.hpp"

BHeap::BHeap() : size(0) {}


void 
BHeap::MakeHeap() {
    //Kode her
}

void
BHeap::sayName() {
    std::cout << "I am BHeap" << std::endl;
}

int
BHeap::FindMin() {

    return 5;
}

void
BHeap::Insert(int i) {
    if(size == 0) {
        auto node = std::make_shared<BNode>(i);
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
    }
    size++;
    //TODO: Bubble-up
}

void
BHeap::DeleteMin() {

}

void 
BHeap::DecreaseKey(int k, int i) {



}
