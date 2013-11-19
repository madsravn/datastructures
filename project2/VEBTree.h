#pragma once

#include <memory>
#include <list>
#include <cassert>
#include <map>
#include <cmath>
#include "BinaryNode.h"
#include "BinaryTree.h"
#include "IQueue.hpp"
#include "ISearch.hpp"

class VEBTree : public IQueue, public ISearch
{
public:
	VEBTree(void);
	~VEBTree(void);

    virtual void MakeHeap();
    
	int comparisons;

	std::shared_ptr<INode> Insert(int key, int value);
	void del(std::shared_ptr<BinaryNode> node);
	virtual int DeleteMin();
    virtual void DecreaseKey(std::shared_ptr<INode> k, int i);
    virtual void sayName();
    virtual bool empty();
    virtual void DecreaseKeyTo(std::shared_ptr<INode> k, int i);
	virtual std::shared_ptr<INode> predecessor(int key);
	virtual int FindMin();

private:
	int universe;
	int size;
	std::shared_ptr<BinaryNode> min;
	std::shared_ptr<BinaryTree> top;
	std::map<int, std::shared_ptr<BinaryTree>> bottom;
};
