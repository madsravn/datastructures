#pragma once

#include <memory>
#include <list>
#include <cassert>
#include "INode.hpp"

class BinaryNode : public INode
{
public:
	BinaryNode(int tkey, int tvalue);
	~BinaryNode(void);

	//int key;
    int value;
	std::shared_ptr<BinaryNode> parent, left, right;
};
