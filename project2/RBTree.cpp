#include "RBTree.h"
#include <string>
#include <iostream>

RBTree::RBTree(void)
{
	
	null = std::make_shared<RBNode>(0, nullptr);
	null->color = false;
	root = null;
	comparisons = 0;
}


RBTree::~RBTree(void)
{
}


void RBTree::insert(int i) {

	//std::cout << toString("tree before insert");

	std::shared_ptr<RBNode> node = std::make_shared<RBNode>(i, null);

	std::shared_ptr<RBNode> y = null;
	std::shared_ptr<RBNode> x = root;

	while(x != null ) {
		y = x;
		comparisons++;
		if (node->key < x->key) {			
			x = x->left;
		} else {
			x = x->right;
		}	
	}
	node->parent = y;

	comparisons++;
	if(y == null) {
		root = node;
	} else if (node->key < y->key) {		
		y->left = node;
	} else {
		y->right = node;
	}
	node->left = null;
	node->right = null;
	node->color = true;

	//std::cout << toString("tree before fixup");
	insertFixup(node);

	//std::cout << toString("tree after fixup");
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
			} else { 
				if (node == node->parent->right) {
					node = node->parent;
					leftRotate(node);
				}
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
			} else {
				if (node == node->parent->left) {
					node = node->parent;
					rightRotate(node);
				}
				node->parent->color = false; // black
				node->parent->parent->color = true; // red
				//toString("tree");
				leftRotate(node->parent->parent);
			}
		}
	}

	root->color = false; // black
}

void RBTree::leftRotate(std::shared_ptr<RBNode> node) {

	assert(node->right != null);

	std::shared_ptr<RBNode> y = node->right;
	node->right = y->left;

	if(y->left != null ) {
		y->left->parent = node;
	}
	y->parent = node->parent;

	if(node->parent == null ) {
		root = y;
	}
	else if (node == node->parent->left) {
		node->parent->left = y;
	}
	else {
		node->parent->right = y;
	}
	y->left = node;
	node->parent = y;
}

void RBTree::rightRotate(std::shared_ptr<RBNode> node) {

	assert(node->left != null);

	std::shared_ptr<RBNode> y = node->left;
	node->left = y->right;

	if(y->right != null ) {
		y->right->parent = node;
	}
	y->parent = node->parent;

	if(node->parent == null) {
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

std::shared_ptr<RBNode> RBTree::search(std::shared_ptr<RBNode> node, int k) {
	if (node == null || k == node->key) {
		return node;
	}

	comparisons++;
	if (k < node->key) {		
		return search(node->left, k);
	} else {
		return search(node->right, k);
	}
}

std::shared_ptr<RBNode> RBTree::search(int k) {
	return search(root, k);
}

void RBTree::del(std::shared_ptr<RBNode> node) {

	//std::cout << toString("before delete");
	std::shared_ptr<RBNode> x;
	std::shared_ptr<RBNode> y = node;
	bool y_original_color = y->color;
	if (node->left == null) {
		x = node->right;
		transplant(node, node->right);
	} else if (node->right == null) {
		x = node->left;
		transplant(node, node->left);
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
		transplant(node, y);
		y->left = node->left;
		y->left->parent = y;
		y->color = node->color;
	}
	if (y_original_color == false) {
		//std::cout << toString("before delFixup");
		delFixup(x);		
	}
}

void RBTree::delFixup(std::shared_ptr<RBNode> node) {
	while (node != root && node->color == false) {
		//std::cout << toString("tree del fixup");
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
			} else {
				if (w->right->color == false) {
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
			}
			
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
	if (u->parent == null) {
		root = v;
	} else if (u == u->parent->left) {
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

std::shared_ptr<RBNode> RBTree::minimum(std::shared_ptr<RBNode> node) {
	while(node->left != null) {
		node = node->left;
	}
	return node;
}

std::shared_ptr<RBNode> RBTree::maximum(std::shared_ptr<RBNode> node) {
	while(node->right != null) {
		node = node->right;
	}
	return node;
}

std::shared_ptr<RBNode> RBTree::successor(std::shared_ptr<RBNode> node) {
	if (node->right != null) {
		return minimum(node->right);
	}
	std::shared_ptr<RBNode> y = node->parent;
	while (y != null && node == y->right) {
		node = y;
		y = y->parent;
	}
	return y;
}

std::shared_ptr<RBNode> RBTree::predecessor(std::shared_ptr<RBNode> node) {
	if (node->left != null) {
		return maximum(node->left);
	}
	std::shared_ptr<RBNode> y = node->parent;
	while (y != null && node == y->left) {
		node = y;
		y = y->parent;
	}
	return y;
}

std::shared_ptr<INode>
RBTree::predecessor(int i) {

}

void RBTree::deleteMin() {
	del(minimum(root));
}

std::string RBTree::toString(std::string label) {
	std::string output = "";
	output += "digraph { \n";
	output += "rankdir=TB;\nB";
	output += "label=\"" + label + " \"; labelloc=top;\n";	
	output += toString(root);
	output += "}\n";

	return output;
}

std::string RBTree::toString(std::shared_ptr<RBNode> node) {

	std::string output = "";

	output += std::to_string(node->key) + "[style=filled, fillcolor=" + ((node->color) ? "red" : "grey") + "]\n";

	if (node->left != nullptr)
		output += std::to_string(node->key) + "->" + std::to_string(node->left->key) + ";\n";
	if(node->right != nullptr)
		output += std::to_string(node->key) + "->" + std::to_string(node->right->key) + ";\n";

	if (node->left != nullptr)
		output += toString(node->left);
	if(node->right != nullptr)
		output += toString(node->right);	
	return output;
}
