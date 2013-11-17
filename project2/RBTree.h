#pragma once

#include <memory>
#include <list>
#include <cassert>
#include "RBNode.h"

class RBTree
{
public:
	RBTree(void);
	~RBTree(void);

	std::shared_ptr<RBNode> root;
	std::shared_ptr<RBNode> null;
	int comparisons;
	
	void insert(int i);
	void insertFixup(std::shared_ptr<RBNode> node);
	std::shared_ptr<RBNode> search(std::shared_ptr<RBNode> node, int k);
	std::shared_ptr<RBNode> search(int k);
	void leftRotate(std::shared_ptr<RBNode> node);
	void rightRotate(std::shared_ptr<RBNode> node);
	void del(std::shared_ptr<RBNode> node);
	void delFixup(std::shared_ptr<RBNode> node);
	void transplant(std::shared_ptr<RBNode> u, std::shared_ptr<RBNode> v);
	std::shared_ptr<RBNode> minimum(std::shared_ptr<RBNode> node);
	std::shared_ptr<RBNode> maximum(std::shared_ptr<RBNode> node);
	std::shared_ptr<RBNode> successor(std::shared_ptr<RBNode> node);
	std::shared_ptr<RBNode> predecessor(std::shared_ptr<RBNode> node);
	void deleteMin();

	std::string toString(std::string label);
	std::string toString(std::shared_ptr<RBNode> node);
};