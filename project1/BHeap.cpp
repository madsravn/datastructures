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

//TODO: Få den til at pege begge veje, så vi også kan holde øje med parents
std::string 
nodeInfo(std::shared_ptr<BNode> n) {
    
    std::string temp = "";

    if(n == nullptr) {
        temp = temp + "";
    }
    if(n->left == nullptr && n->right == nullptr) {
        temp = temp + ""; 
    }
    if(n->left != nullptr) {
        temp = temp + std::to_string(n->prio) + " -> " + std::to_string( n->left->prio) + "\n";
        temp = temp + nodeInfo(n->left);
    }
    if(n->right != nullptr) {
        temp = temp + std::to_string(n->prio) + " -> " + std::to_string( n->right->prio) + "\n";

        temp = temp + nodeInfo(n->right);
    }
    if(n->parent != nullptr) {
        temp = temp + std::to_string(n->prio) + " -> " + std::to_string(n->parent->prio) + "\n";
    }
    return temp;
}

std::string
BHeap::graph() {
    return  "digraph G {\n\n" + nodeInfo(root) + "\n}";
}

int
BHeap::FindMin() {
    if(size > 0) {
        return root->key ;
    }
    return -1;
}

// TODO: Rewrite til at bruge Find i stedet for
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
        auto newnode = std::make_shared<BNode>(k, priority);
        if(s.at(pos) == '0') {
            node->left = newnode;
        }
        if(s.at(pos) == '1') {
            node->right = newnode;
        }
        newnode->parent = node;
        BubbleUp(newnode); 
        /*while(newnode->parent != nullptr) {
            if(newnode->prio < newnode->parent->prio) {
                //int tprio = newnode->prio;
                //newnode->prio = newnode->parent->prio;
                //newnode->parent->prio = tprio;
                //int tkey = newnode->key;
                //newnode->key = newnode->parent->key;
                //newnode->parent->key = tkey;
                Switch(newnode, newnode->parent);
            }
            newnode = newnode->parent;
        }*/

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
    root->parent = nullptr;
    BubbleDown(root);
}

void
BHeap::BubbleDown(std::shared_ptr<BNode> node) {
    // Der skal køres nedad, men også tages højde for at enten left eller right kan være nullptr
    if(node->left != nullptr && node->right != nullptr) {
        if(node->left->prio < node->right->prio) {
            if(node->left->prio < node->prio) {
                Switch(node,node->left);
                BubbleDown(node->left);
            }
        } else {
            if(node->right->prio < node->prio) {
                Switch(node,node->right);
                BubbleDown(node->right);
            }
        }
    } else if(node->left != nullptr) {
        if(node->left->prio < node->prio) {
            Switch(node,node->left);
            BubbleDown(node->left);
        }
    } else if(node->right != nullptr) {
        if(node->right->prio < node->prio) {
            Switch(node,node->right);
            BubbleDown(node->right);
        }
    }

}

void internalNodeInfo(std::shared_ptr<BNode> node) {
    if(node->parent != nullptr) {
        std::cout << "nodeID: " << node << " and node->parentID: " << node->parent << std::endl;
        std::cout << "node->prio = " << node->prio << " and node->parent->prio = " << node->parent->prio << std::endl;
        std::cout << "===" << std::endl;
    }
}

void
BHeap::BubbleUp(std::shared_ptr<BNode> node) {

    if(node->parent != nullptr) {
        if(node->parent->prio > node->prio) {
            Switch(node,node->parent);
            BubbleUp(node->parent);
        }
    }

}

// TODO: Implementeringsspørgsmål.
// Vi burde skifte rundt på hele noder i stedet for bare interne værdier.
// Hvis der er andet der peger på noderne bliver de ved med at pege på det samme.
// Men er der nogensinde en situation hvor det sker (at der er noget ude fra der internt på vores nodes?
void 
BHeap::Switch(std::shared_ptr<BNode> n1, std::shared_ptr<BNode> n2) {
    
    /*
    //TODO: FIX!
    // Imidlertidige værdier
    std::shared_ptr<BNode> tparent = n1->parent;
    std::shared_ptr<BNode> tleft = n1->left;
    std::shared_ptr<BNode> tright = n1->right;
    // Vi bytter rundt på hvad de peger på.
    if(n1 != root) {
        if(n1->parent->left == n1) {
            n1->parent->left = n2;
        }
        if(n1->parent->right == n1) {
            n1->parent->right = n2;
        }
    } else {
        root = n2;
    }
    if(n2 != root) {
        if(n2->parent->left == n2) {
            n2->parent->left = n1;
        }
        if(n2->parent->right = n2) {
            n2->parent->right = n1;
        }
    } else {
        root = n1;
    }

    n1->parent = n2->parent;
    n1->left = n2->left;
    n1->right = n2->right;
    n2->parent = tparent;
    n2->left = tleft;
    n2->right = tright;
    if(n2->right != nullptr) {
        n2->right->parent = n2;
    }
    if(n2->left != nullptr) {
        n2->left->parent = n2;
    }
    if(n1->left != nullptr) {
        n1->left->parent = n1;
    }
    if(n1->right != nullptr) {
        n1->right->parent = n2;
    }
    */
    
    int tkey = n1->key;
    int tprio = n1->prio;
    n1->key = n2->key;
    n1->prio = n2->prio;
    n2->key = tkey;
    n2->prio = tprio;
    

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
