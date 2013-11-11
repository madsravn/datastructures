#pragma once

#include <memory>
#include <list>
#include <cassert>

class BinaryNode
{
public:
	BinaryNode(int key);
	~BinaryNode(void);

	int key;
	std::shared_ptr<BinaryNode> parent, left, right;
};
