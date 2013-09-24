#ifndef FNODE_HPP_
#define FNODE_HPP_

#include <memory>
#include <list>

class FNode {
    public:
        FNode(int key, int priority);
        FNode();
        
        

	int rank;
	bool marked;
	std::shared_ptr<FNode> parent, child, leftSibling, rightSibling;
    int n;
	int key;
	bool null;

};

#endif
