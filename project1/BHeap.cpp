#include "BHeap.hpp"

BHeap::BHeap() : size(0), root(nullptr) {
    ups = downs = inserts = lookups = deletions = swaps = 0;
}

void 
BHeap::MakeHeap() {
    //Kode her
}

void
BHeap::printInformation() {
    std::cout << "ups: " << ups << std::endl;
    std::cout << "downs: " << downs << std::endl;
    std::cout << "inserts: " << inserts << std::endl;
    std::cout << "lookups: " << lookups << std::endl;
    std::cout << "deletions: " << deletions << std::endl;
    std::cout << "swaps: " << swaps << std::endl;
}

void
BHeap::sayName() {
    std::cout << "I am BHeap" << std::endl;
}

bool
BHeap::empty() {
    return (size == 0);
}

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
        temp = temp + std::to_string(n->key) + " -> " + std::to_string(n->left->key) + "\n";
        temp = temp + nodeInfo(n->left);
    }
    if(n->right != nullptr) {
        temp = temp + std::to_string(n->key) + " -> " + std::to_string(n->right->key) + "\n";

        temp = temp + nodeInfo(n->right);
    }
    if(n->parent != nullptr) {
        temp = temp + std::to_string(n->key) + " -> " + std::to_string(n->parent->key) + "\n";
    }
    return temp;
}

std::string
BHeap::graph() {
    if(root == nullptr) {
        return "digraph G {\n\n EMTPY \n\n}";
    }
    return  "digraph G {\n\n" + nodeInfo(root) + "\n}";
}

int
BHeap::FindMin() {
    if(size > 0) {
        return root->key ;
    }
    return -1;
}

void internalNodeInfo(std::shared_ptr<BNode> node) {
    if(node == nullptr) {
        std::cout << "something's fishy" << std::endl;
    } else {
        if(node->parent == nullptr) {
            std::cout << "parent: null" << std::endl;
        } else {
            std::cout << "parent -> " << node->parent << std::endl;
        }
        if(node->right == nullptr) {
            std::cout << "right: null" << std::endl;
        } else {
            std::cout << "right -> " << node->right << std::endl;
        }
        if(node->left == nullptr) {
            std::cout << "left: null" << std::endl;
        } else {
            std::cout << "left -> " << node->left << std::endl;
        }
    }
    std::cout << " = = = " << std::endl;
}
/*
void 
BHeap::Swap() {
    int i = size;
    std::shared_ptr<BNode> n1 = Find(size-2);
    std::shared_ptr<BNode> n2 = Find(size-3);
    std::shared_ptr<BNode> t1left = n1->left;
    std::shared_ptr<BNode> t1right = n1->right;
    std::shared_ptr<BNode> t1parent = n1->parent;
    std::shared_ptr<BNode> t2left = n2->left;
    std::shared_ptr<BNode> t2right = n2->right;
    std::shared_ptr<BNode> t2parent = n2->parent;
    if(n2->parent != nullptr) {
        if(n2->parent->left == n2) {
            n2->parent->left = n1;
        } else if(n2->parent->right == n2) {
            n2->parent->right = n1;
        }
    } else {
        root = n2;
    }
    if(n1->parent != nullptr) {
        if(n1->parent->left == n1) {
            n1->parent->left = n2;
        } else if(n1->parent->right == n1) {
            n1->parent->right = n2;
        }
    } else {
        root = n1;
    }
    if(n1->left != nullptr) {
        n1->left->parent = n2;
    }
    if(n1->right != nullptr) {
        n1->right->parent = n2;
    }
    if(n2->left != nullptr) {
        n2->left->parent = n1;
    }
    if(n2->right != nullptr) {
        n2->right->parent = n1;
    }
    n1->left = n2->left;
    n1->right = n2->right;
    n1->parent = n2->parent;
    n2->left = t1left;
    n2->right = t1right;
    n2->parent = t1parent;

}
*/


std::shared_ptr<INode>
BHeap::Insert(int k, int priority) {
    if(size == 0) {
        std::shared_ptr<BNode> node = std::make_shared<BNode>(k, priority);
        root = node;
        inserts++;
        size++;
        return node;
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
        std::shared_ptr<BNode> newnode = std::make_shared<BNode>(k, priority);
        if(s.at(pos) == '0') {
            node->left = newnode;
        }
        if(s.at(pos) == '1') {
            node->right = newnode;
        }
        newnode->parent = node;
        BubbleUp(newnode); 

        inserts++;

        size++;
        return newnode;
    }
}

int
BHeap::DeleteMin() {
	int retVal = root->key;
    // Tag den sidste node
    std::shared_ptr<BNode> node = Find(size);

    deletions++;
    if(size>3) {
        swaps++;
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
        root->parent = nullptr;

    } else if(size == 2) {
        Switch(node,root);
        root->left->parent = nullptr;
        root->left = nullptr;
    }else if(size == 3) {
        Switch(node,root);
        root->right->parent = nullptr;
        root->right = nullptr;
    }else if(size == 1) {
        root = nullptr;
    }
    size--;
    if(size>0) {
        BubbleDown(root);
    }

    //std::cout << graph() << std::endl;
	return retVal;
}

//TODO: Refactor
void
BHeap::BubbleDown(std::shared_ptr<BNode> node) {
    downs++;
    if(node->left != nullptr && node->right != nullptr) {
        if(node->left->prio < node->right->prio) {
            if(node->left->prio < node->prio) {
                Switch(node->left,node);
                BubbleDown(node); //node->left
            }
        } else {
            if(node->right->prio < node->prio) {
                Switch(node->right,node);
                BubbleDown(node); //node->right
            }
        }
    } else if(node->left != nullptr) {
        if(node->left->prio < node->prio) {
            Switch(node->left,node);
            BubbleDown(node); //node->left
        }
    } else if(node->right != nullptr) {
        if(node->right->prio < node->prio) {
            Switch(node->right,node);
            BubbleDown(node); //node->right
        }
    }

}



void
BHeap::BubbleUp(std::shared_ptr<BNode> node) {
    ups++;

    if(node->parent != nullptr) {
        if(node->parent->prio > node->prio) {
            Switch(node,node->parent);
            // Since node and node->parent has switched, node=node->parent
            BubbleUp(node);
        }
    }

}

void 
BHeap::Switch(std::shared_ptr<BNode> n1, std::shared_ptr<BNode> n2) {
    
    assert(n1->parent == n2);

    swaps++;
    std::shared_ptr<BNode> tleft = n1->left;
    std::shared_ptr<BNode> tright = n1->right;
    std::shared_ptr<BNode> tparent = n1->parent;
    if(n2 == root) {
        n1->parent = nullptr;
        root = n1;
    } else {
        n1->parent = n2->parent;
        if(n2->parent->right == n2) {
            n2->parent->right = n1;
        } else if(n2->parent->left == n2) {
            n2->parent->left = n1;
        }
    }
    if(n2->right == n1) {
        n1->right = n2;
        n1->left = n2->left;
        if(n1->left != nullptr) {
            n1->left->parent = n1;
        }
    } else if(n2->left == n1) {
        n1->left = n2;
        n1->right = n2->right;
        if(n1->right != nullptr) {
            n1->right->parent = n1;
        }
    }
    n2->parent = n1;

    n2->left = tleft;
    n2->right = tright;
    if(n2->left != nullptr) {
        n2->left->parent = n2;
    }
    if(n2->right != nullptr) {
        n2->right->parent = n2;
    }
    /*int tkey = n1->key;
    int tprio = n1->prio;
    n1->key = n2->key;
    n1->prio = n2->prio;
    n2->key = tkey;
    n2->prio = tprio;*/

     
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
BHeap::DecreaseKey(std::shared_ptr<INode> k, int i) {
    lookups++;
    std::shared_ptr<BNode> node = std::static_pointer_cast<BNode>(k);
    node->prio = node->prio-i;
    BubbleUp(node);

}
