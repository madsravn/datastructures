#include "VEBTree.h"

VEBTree::VEBTree()
{
	this->universe = pow(2, 24);
	this->size = 0;
	this->top = std::shared_ptr<BinaryTree>(new BinaryTree());
}

VEBTree::~VEBTree(void)
{
}

std::shared_ptr<BinaryNode> VEBTree::insert(int key)
{
	// Ensure only keys in the universe
	if(key > universe) return nullptr;

	std::shared_ptr<BinaryNode> node = std::shared_ptr<BinaryNode>(new BinaryNode(key));

	if(size == 0) {
		size++;
		min = node;

		return node;
	}
	else
	{
		if(min->key > node->key)
		{
			std::shared_ptr<BinaryNode> temp = min;
			min = node;
			node = temp;
		}

		short a = node->key >> 12;

		if(bottom[a] == nullptr)
			bottom[a] = std::shared_ptr<BinaryTree>(new BinaryTree());

		if(bottom[a]->root == nullptr)
			top->insert(a);

		bottom[a]->insert(node);

		size++;

		return node;
	}
}

void VEBTree::del(std::shared_ptr<BinaryNode> node)
{
	// If there is only one element, we simply delete min (possibly we should check if it is in fact the correct element)
	if(size <= 1){
		size--;
		min = nullptr;

		return;
	}
	
	// If we are deleting the minimum node, we replace with a new minimum and delete the new min from its tree
	if(min = node){
		node = (min = bottom[top->min->key]->min);
	}

	short a = node->key >> 12;

	bottom[a]->del(node);

	if(bottom[a]->root == nullptr){
		std::shared_ptr<BinaryNode> topNode = top->predecessor(a);
		if(topNode->key == a)
			top->del(topNode);
	}

	size--;
}

void VEBTree::delMin()
{
	this->del(min);
}

std::shared_ptr<BinaryNode> VEBTree::predecessor(int key)
{
	std::shared_ptr<BinaryNode> result;

	short a = key >> 12;

	if(bottom[a] != nullptr && bottom[a]->min->key <= key)
		result = bottom[a]->predecessor(key);
	else
		result = bottom[top->predecessor(a)->key]->max;

	if(min->key <= key && min->key > result->key)
		result = min;

	return result;
}

std::shared_ptr<BinaryNode> VEBTree::FindMin()
{
	return min;
}
