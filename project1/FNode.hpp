#ifndef FNODE_HPP_
#define FNODE_HPP_

#include <memory>
#include <list>

class FNode {
public:
	FNode(int key, int priority);
	FNode();


	int n;
	std::shared_ptr<FNode> parent, child, leftSibling, rightSibling;
	int rank;
	bool marked;	
	int key;
	bool null;

};

#endif
