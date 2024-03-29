#include "VEBTree.h"

VEBTree::VEBTree()
{
	this->universe = pow(2, 24);
	this->size = 0;
	this->top = std::shared_ptr<BinaryTree>(new BinaryTree());
    comparisons = 0;
}

VEBTree::~VEBTree(void)
{
}

void
VEBTree::MakeHeap() {
}


std::shared_ptr<INode> VEBTree::Insert(int key, int value)
{
	// Ensure only keys in the universe
	if(key > universe) return nullptr;

	std::shared_ptr<BinaryNode> node = std::shared_ptr<BinaryNode>(new BinaryNode(key, value));

	if(size == 0) {
		size++;
		min = node;

		return node;
	}
	else
	{
        comparisons++;
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
			top->insert(a, value); //TODO: Korrekt?

		bottom[a]->insert(node);

		size++;

        comparisons += top->getComparisons();
        comparisons += bottom[a]->getComparisons();
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
	if(min == node){ 
		node = (min = bottom[top->min->key]->min);
	}

	short a = node->key >> 12;

	bottom[a]->del(node);

	if(bottom[a]->root == nullptr){
		std::shared_ptr<BinaryNode> topNode = top->predecessor(a);
		if(topNode->key == a)
			top->del(topNode);
        comparisons++;
	}

	size--;
}

int VEBTree::DeleteMin()
{
	this->del(min);
	return 0; // TODO: Return correct value
}

void
VEBTree::DecreaseKey(std::shared_ptr<INode> k, int i) {
    std::shared_ptr<BinaryNode> node = std::static_pointer_cast<BinaryNode>(k);
	del(node);
	Insert(node->key - i, node->value); 
}

void 
VEBTree::sayName() {
}

bool
VEBTree::empty() {
	return 0; //TODO: Return correct value
}

void
VEBTree::DecreaseKeyTo(std::shared_ptr<INode> k, int i) {
    std::shared_ptr<BinaryNode> node = std::static_pointer_cast<BinaryNode>(k);

}


std::shared_ptr<INode> VEBTree::predecessor(int key)
{
	std::shared_ptr<BinaryNode> result;

	short a = key >> 12;

	if(bottom[a] != nullptr && bottom[a]->min->key <= key) {
		result = bottom[a]->predecessor(key);
        comparisons += bottom[a]->getComparisons();
    } else {
		if(top->min->key > a)
			return nullptr;
        int tkey = top->predecessor(a)->key;
		result = bottom[tkey]->max;
        comparisons += bottom[tkey]->getComparisons();
    }
    comparisons++;

	if(min->key <= key && min->key > result->key)
		result = min;
    comparisons++;

	return result;
}

int VEBTree::FindMin()
{
	return min->value;
}
