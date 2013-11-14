#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(void)
{
	root = nullptr;
	min = nullptr;
	max = nullptr;
    comparisons = 0;
}

BinaryTree::~BinaryTree(void)
{
}

int
BinaryTree::getComparisons() {
    int temp = comparisons;
    comparisons = 0;
    return temp;
}

std::shared_ptr<BinaryNode> BinaryTree::insert(std::shared_ptr<BinaryNode> newNode)
{
	// If no other nodes has been added, insertion is simply to set min, max and root to the new node
	if(root == nullptr)
	{
		root = newNode;
		min = root;
		max = root;
		return newNode;
	}

	// Test if this is a new max or min
	if(min->key > newNode->key)
		min = newNode;

	if(max->key < newNode->key)
		max = newNode;

    comparisons += 2;
	// Insert the node
	insertRecursive(root, newNode);
	
	return newNode;
}

std::shared_ptr<BinaryNode> BinaryTree::insert(int key)
{
	std::shared_ptr<BinaryNode> newNode = std::shared_ptr<BinaryNode>(new BinaryNode(key));

	return insert(newNode);
}

void BinaryTree::del(std::shared_ptr<BinaryNode> node)
{
	// If the node is a leaf
	if(node->left == nullptr && node->right == nullptr) {
		std::shared_ptr<BinaryNode> switchNode = node->parent;
		
		if(node != root) {
			if(node->parent->right == node)
				node->parent->right = nullptr;
			if(node->parent->left == node)
				node->parent->left = nullptr;
		}
		else
		{
			root = switchNode;
		}

		if(max == node)
			max = switchNode;
		if(min == node)
			min = switchNode;

		return;
	}

	// If the node only has a left child
	if(node->left != nullptr && node->right == nullptr) {
		node->left->parent = node->parent;
		
		if(node == root) {
			root = node->left;
		}
		else {
			if(node->parent->right == node)
				node->parent->right = node->left;
			if(node->parent->left == node)
				node->parent->left = node->left;
		}

		if(max == node)
			max = searchMax(node->left);

		return;
	}

	// If the node only has a right child
	if(node->left == nullptr && node->right != nullptr) {
		node->right->parent = node->parent;

		if(node == root) {
			root = node->right;
		}
		else {
			if(node->parent->right == node)
				node->parent->right = node->right;
			if(node->parent->left == node)
				node->parent->left = node->right;
		}

		if(min == node)
			min = searchMin(node->right);

		return;
	}

	// If the node has two children
	if(node->left != nullptr && node->right != nullptr) {
		std::shared_ptr<BinaryNode> rNode = searchMin(node->right);

		// Remove rNode from the tree
		if(rNode->right != nullptr){
			rNode->right->parent = rNode->parent;
			rNode->parent->left = rNode->right;
		}

		// Replace node with rNode
		rNode->parent = node->parent;
		rNode->left = node->left;
		rNode->right = node->right;

		node->left->parent = rNode;
		node->right->parent = rNode;
		
		if(node == root){
			root = rNode;
		}
		else {
			if(node->parent->right == node)
				node->parent->right = rNode;
			if(node->parent->left == node)
				node->parent->left = rNode;
		}

		return;
	}
}

std::shared_ptr<BinaryNode> BinaryTree::predecessor(int key)
{
	std::shared_ptr<BinaryNode> bestMatch, node = root;

	while(node != nullptr) {
		if(node == nullptr || node->key == key) {
            comparisons++;
			return node;
        }
		else if(node->key < key) {
			bestMatch = node;
			node = node->right;
            comparisons++;
		}
		else {
			node = node->left;
		}
	}

	return bestMatch;
}

void BinaryTree::print()
{
	std::cout << "Max: " << max->key << ", Min: " << min->key << std::endl;
	print(root);
}

/*
 * Private functions
 */

std::shared_ptr<BinaryNode> BinaryTree::searchMax(std::shared_ptr<BinaryNode> node)
{
	while(node->right != nullptr)
		node = node->right;

	return node;
}

std::shared_ptr<BinaryNode> BinaryTree::searchMin(std::shared_ptr<BinaryNode> node)
{
	while(node->left != nullptr)
		node = node->left;

	return node;
}

void BinaryTree::print(std::shared_ptr<BinaryNode> node)
{
	if(node->left != nullptr && node->right != nullptr) {
		std::cout << node->key << "{" << node->left->key << "," << node->right->key << "}" << std::endl;
		print(node->left);
		print(node->right);
	}
	else
	{
		if(node->left != nullptr) {
			std::cout << node->key << "{" << node->left->key << ",E}" << std::endl;
			print(node->left);
		}
		else if(node->right != nullptr) {
			std::cout << node->key << "{E," << node->right->key << "}" << std::endl;
			print(node->right);
		}
		else {
			std::cout << node->key << "{E,E}" << std::endl;
		}
	}
}

void BinaryTree::insertRecursive(std::shared_ptr<BinaryNode> start, std::shared_ptr<BinaryNode> node)
{
	if(node->key < start->key) {
        comparisons++;
		if(start->left == nullptr) {
			start->left = node;
			node->parent = start;
		}
		else
			insertRecursive(start->left, node);
	}
	else {
		if(start->right == nullptr) {
			start->right = node;
			node->parent = start;
		}
		else
			insertRecursive(start->right, node);
	}
}
