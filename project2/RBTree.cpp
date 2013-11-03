#include "RBTree.h"


RBTree::RBTree(void)
{
}


RBTree::~RBTree(void)
{
}

void RBTree::insert(std::shared_ptr<RBNode> node) {
	std::shared_ptr<RBNode> y = nullptr;
	std::shared_ptr<RBNode> x = root;

	while(x != nullptr ) {
		y = x;
		if (node->key < x->key) {
			x = x->left;
		} else {
			x = x->right;
		}	
	}
	node->parent = y;
	if(y == nullptr) {
		root = node;
	} else if (node->key < y->key) {
		y->left = node;
	} else {
		y->right = node;
	}
	node->left = nullptr;
	node->right = nullptr;
	node->color = true;
	insertFixup(node);
};


void RBTree::insertFixup(std::shared_ptr<RBNode> node){
	while (node->parent->color == true) {// is red		
		if (node->parent == node->parent->parent->left) {
			std::shared_ptr<RBNode> y = node->parent->parent->right;
			if(y->color == true) {// is red
				node->parent->color = false; // black
				y->color = false; // black
				node->parent->parent->color = true; // red
				node = node->parent->parent;			
			} else if (node == node->parent->right) {
				node = node->parent;
				leftRotate(node);
				node->parent->color = false; // black
				node->parent->parent->color = true; // red
				rightRotate(node->parent->parent);
			}
		} else {
			std::shared_ptr<RBNode> y = node->parent->parent->left;
			if(y->color == true) {// is red
				node->parent->color = false; // black
				y->color = false; // black
				node->parent->parent->color = true; // red
				node = node->parent->parent;			
			} else if (node == node->parent->left) {
				node = node->parent;
				rightRotate(node);
				node->parent->color = false; // black
				node->parent->parent->color = true; // red
				leftRotate(node->parent->parent);
			}
		}
	}
	root->color = false; // black
}

void RBTree::leftRotate(std::shared_ptr<RBNode> node) { // TODO: Flyt over i en tree klasse

	assert(node->right != nullptr);

	std::shared_ptr<RBNode> y = node->right;
	node->right = y->left;

	if(y->left != nullptr ) {
		y->left->parent = node;
	}
	y->parent = node->parent;

	if(node->parent == nullptr ) {
		root = y;
	}
	else if (node == node->parent ->left) {
		node->parent ->left = y;
	}
	else {
		node->parent->right = y;
	}
	y->left = node;
	node->parent = y;
}

void RBTree::rightRotate(std::shared_ptr<RBNode> node) {

	assert(node->left != nullptr);

	std::shared_ptr<RBNode> y = node->left;
	node->left = y->right;

	if(y->right != nullptr ) {
		y->right->parent = node;
	}
	y->parent = node->parent;

	if(node->parent == nullptr ) {
		root = y;
	}
	else if (node == node->parent->right) {
		node->parent->right = y;
	}
	else {
		node->parent->left = y;
	}
	y->right = node;
	node->parent = y;
}