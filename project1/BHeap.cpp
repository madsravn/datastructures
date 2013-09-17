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

//TODO: Få den til at pege begge veje, så vi også kan holde øje med parents
std::string 
nodeInfo(std::shared_ptr<BNode> n) {
    if(n == nullptr) {
        return "";
    }
    if(n->left == nullptr && n->right == nullptr) {
        return ""; 
    }
    std::string temp = "";
    if(n->left != nullptr) {
        temp = temp + std::to_string(n->prio) + " -> " + std::to_string( n->left->prio) + "\n";
        temp = temp + nodeInfo(n->left);
    }
    if(n->right != nullptr) {
        temp = temp + std::to_string(n->prio) + " -> " + std::to_string( n->right->prio) + "\n";

        temp = temp + nodeInfo(n->right);
    }
    return temp;
}

std::string
BHeap::graph() {
    return  "digraph G {\n\n" + nodeInfo(root) + "\n}";
}

//TODO: Find ud af hvordan interface skal implementere med både std::shared_ptr<FNODE,BNODE>.
int
BHeap::FindMin() {
    if(size > 0) {
        return root->key ;
    }
    return -1;
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
        auto newnode = std::make_shared<BNode>(k,priority);
        if(s.at(pos) == '0') {
            node->left = newnode;
        }
        if(s.at(pos) == '1') {
            node->right = newnode;
        }
        newnode->parent = node;
        //TODO: FIX! Skal have byttet både parent og børn.
        while(newnode->parent != nullptr) {
            if(newnode->prio < newnode->parent->prio) {
                int temp = newnode->prio;
                newnode->prio = newnode->parent->prio;
                newnode->parent->prio = temp;
                //std::cout << newnode->n << " bytter plads med " << newnode->parent->n << std::endl;
            }
            newnode = newnode->parent;
        }

    }
    size++;
}

void
BHeap::DeleteMin() {

    std::shared_ptr<BNode> node = Find(size);
    node->left = root->left;
    node->right = root->right;
    root->left->parent = node;
    root->right->parent = node;
    root = node;
    if(node->parent->left == node) {
        // node is parents left node
        node->parent->left = nullptr;
    }
    if(node->parent->right == node) {
        // node is parents right node
        node->parent->right = nullptr;
    }
    size--;
}

void
BHeap::BubbleDown(std::shared_ptr<BNode> node) {

}

std::shared_ptr<BNode> 
BHeap::Find(int place) {

    // assert place > 0 and place < size+1
    std::string s = std::bitset<64> (place).to_string();
    size_t pos = 0;
    while(pos < s.size() && s.at(pos) == '0') {
        pos++;
    }
    pos++;
    std::shared_ptr<BNode> node = root;
    while(pos < s.size()) {
        if(s.at(pos) == '0') {
            node = node->left;
        }
        if(s.at(pos) == '1') {
            node = node->right;
        }
        pos++;
    }

    return node;
}


void 
BHeap::DecreaseKey(int k, int i) {



}
