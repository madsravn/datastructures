#pragma once

#include <memory>
#include <list>
#include <cassert>

class RBNode
{
public:
	RBNode(void);
	~RBNode(void);

	bool isRed();
	int key;
	std::shared_ptr<RBNode> parent, left, right;
	bool color; // false for black, true for red

};

