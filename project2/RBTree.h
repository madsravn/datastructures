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
	
	void insert(std::shared_ptr<RBNode> node);
	void insertFixup(std::shared_ptr<RBNode> node);
	void leftRotate(std::shared_ptr<RBNode> node);
	void rightRotate(std::shared_ptr<RBNode> node);
};

