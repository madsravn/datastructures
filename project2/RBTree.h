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
	void del(std::shared_ptr<RBNode> node);
	void delFixup(std::shared_ptr<RBNode> node);
	void transplant(std::shared_ptr<RBNode> u, std::shared_ptr<RBNode> v);
	std::shared_ptr<RBNode> minimum(std::shared_ptr<RBNode> node);
};