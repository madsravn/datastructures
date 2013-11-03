#pragma once

#include <memory>
#include <list>
#include <cassert>
#include "RBTree.h"

class RBNode
{
public:
	RBNode(void);
	~RBNode(void);

	int key;
	std::shared_ptr<RBNode> parent, left, right;
	bool color; // false for black, true for red

};

