#include "RBTree.h"


RBTree::RBTree(void)
{
	root = nullptr;
	comparisons = 0;
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
			comparisons++;
			x = x->left;
		} else {
			x = x->right;
		}	
	}
	node->parent = y;
	if(y == nullptr) {
		root = node;
	} else if (node->key < y->key) {
		comparisons++;
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

void RBTree::leftRotate(std::shared_ptr<RBNode> node) {

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

void RBTree::del(std::shared_ptr<RBNode> node) {
	std::shared_ptr<RBNode> x;
	std::shared_ptr<RBNode> y = node;
	bool y_original_color = y->color;
	if (node->left == nullptr) {
		x = node->right;
		transplant(node, node->right);
	} else if (node->right == nullptr) {
		 x = node->left;
		transplant(node, node->right);
	} else {
		y = minimum(node->right);
		x = y->right;
		if (y->parent == node) {
			x->parent = y;
		} else {
			transplant(y, y->right);
			y->right = node->right;
			y->right->parent = y;
		}
		transplant(node,y);
		y->left = node->left;
		y->left->parent = y;
		y->color = node->color;
	}
	if (y_original_color == false) {
		delFixup(x);
	}
}

void RBTree::delFixup(std::shared_ptr<RBNode> node) {
	while (node != root && node->color == false) {
		if (node == node->parent->left) {
			std::shared_ptr<RBNode> w = node->parent->right;
			if (w->color == true) {
				w->color = false;
				node->parent->color = true;
				leftRotate(node->parent);
				w = node->parent->right;
			}
			if (w->left->color == false && w->right->color == false) {
				w->color = true;
				node = node->parent;
			} else if (w->right->color == false) {
				w->left->color = false;
				w->color = true;
				rightRotate(w);
				w = node->parent->right;
			}
			w->color = node->parent->color;
			node->parent->color = false;
			w->right->color = false;
			leftRotate(node->parent);
			node = root;
		} else {
			std::shared_ptr<RBNode> w = node->parent->left;
			if (w->color == true) {
				w->color = false;
				node->parent->color = true;
				rightRotate(node->parent);
				w = node->parent->left;
			}
			if (w->right->color == false && w->left->color == false) {
				w->color = true;
				node = node->parent;
			} else if (w->left->color == false) {
				w->right->color = false;
				w->color = true;
				leftRotate(w);
				w = node->parent->left;
			}
			w->color = node->parent->color;
			node->parent->color = false;
			w->left->color = false;
			rightRotate(node->parent);
			node = root;
		}
	}
	node->color = false;
}

void RBTree::transplant(std::shared_ptr<RBNode> u, std::shared_ptr<RBNode> v) {
	if (u->parent == nullptr) {
		root = v;
	} else if (u == u->parent->left) {
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

std::shared_ptr<RBNode> RBTree::minimum(std::shared_ptr<RBNode> node) {
	while(node->left != nullptr) {
		node = node->left;
	}
	return node;
}

std::shared_ptr<RBNode> RBTree::maximum(std::shared_ptr<RBNode> node) {
	while(node->right != nullptr) {
		node = node->right;
	}
	return node;
}

std::shared_ptr<RBNode> RBTree::successor(std::shared_ptr<RBNode> node) {
	if (node->right != nullptr) {
		return minimum(node->right);
	}
	std::shared_ptr<RBNode> y = node->parent;
	while (y != nullptr && node == y->right) {
		node = y;
		y = y->parent;
	}
	return y;
}

std::shared_ptr<RBNode> RBTree::predecessor(std::shared_ptr<RBNode> node) {
	if (node->left != nullptr) {
		return maximum(node->left);
	}
	std::shared_ptr<RBNode> y = node->parent;
	while (y != nullptr && node == y->left) {
		node = y;
		y = y->parent;
	}
	return y;
}