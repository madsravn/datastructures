#pragma once

#include <memory>
#include <list>
#include <cassert>
#include <map>
#include <cmath>
#include "BinaryNode.h"
#include "BinaryTree.h"

class VEBTree
{
public:
	VEBTree(void);
	~VEBTree(void);

	int comparisons;

	std::shared_ptr<BinaryNode> insert(int key);
	void del(std::shared_ptr<BinaryNode> node);
	void delMin();
	std::shared_ptr<BinaryNode> predecessor(int key);
	std::shared_ptr<BinaryNode> FindMin();

private:
	int universe;
	int size;
	std::shared_ptr<BinaryNode> min;
	std::shared_ptr<BinaryTree> top;
	std::map<int, std::shared_ptr<BinaryTree>> bottom;
};
