#pragma once

#include <memory>
#include <list>
#include <cassert>
#include "BinaryNode.h"

class BinaryTree
{
public:
	BinaryTree(void);
	~BinaryTree(void);

	std::shared_ptr<BinaryNode> min, max, root;

	std::shared_ptr<BinaryNode> insert(int key);
	std::shared_ptr<BinaryNode> insert(std::shared_ptr<BinaryNode> newNode);
	void del(std::shared_ptr<BinaryNode> node);
	std::shared_ptr<BinaryNode> predecessor(int key);
	
	void print();
    int getComparisons();

private:
    int comparisons;
	std::shared_ptr<BinaryNode> searchMin(std::shared_ptr<BinaryNode> node);
	std::shared_ptr<BinaryNode> searchMax(std::shared_ptr<BinaryNode> node);
	void insertRecursive(std::shared_ptr<BinaryNode> start, std::shared_ptr<BinaryNode> node);
	void print(std::shared_ptr<BinaryNode> node);
};
