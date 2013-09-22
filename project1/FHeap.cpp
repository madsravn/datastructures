#include "FHeap.hpp"
#include "FNode.hpp"
#include <cassert>
#include <string>
FHeap::FHeap() {

}

std::string FHeap::toString(std::string label) {
	std::shared_ptr<FNode> tempNode = std::make_shared<FNode>();
	tempNode->child = minRoot;
	minRoot->parent = tempNode;

	std::string output = "";
	output += "digraph " + std::to_string(minRoot->n) + " { \n";
	output += "label=\"" + label + " \"; labelloc=top;";
	output += nodeInfo(tempNode, 0);
	output += "}\n";
	minRoot->parent = nullptr;

	return output;
}

void 
FHeap::MakeHeap() {
	minRoot = nullptr;	
}

void
FHeap::sayName() {
	std::cout << "I am FHeap" << std::endl;
}

int
FHeap::FindMin() {
	return minRoot->n;
}

void
FHeap::Insert(int k, int priority) {
	if (minRoot != nullptr) {
		std::shared_ptr<FHeap> heap = std::make_shared<FHeap>();
		heap->Insert(k, priority);
		Meld(heap);
	} else {
		std::shared_ptr<FNode> node = std::make_shared<FNode>(priority);
		node->child = nullptr;
		node->parent = nullptr;
		node->leftSibling = node;
		node->rightSibling = node;
		node->rank = 0;
		node->marked = true; // Dunno wtf
		minRoot = node;
	}
}

void
FHeap::DeleteMin() {
	auto root = minRoot;
	
	std::vector<std::shared_ptr<FNode>> roots;

	// Add other roots to list
	
	
	if (minRoot != nullptr) {
		std::shared_ptr<FNode> rootSibling = minRoot->rightSibling;
		if (minRoot->leftSibling == minRoot) {
			roots.push_back(minRoot);
		}
		while(rootSibling != minRoot) {
			roots.push_back(rootSibling);
			rootSibling = rootSibling->rightSibling;
		}
	}
	

	// Add deleted node's children to list
	if(minRoot->child != nullptr) {
		roots.push_back(minRoot->child);
		std::shared_ptr<FNode> rootSibling = minRoot->child->rightSibling;
		if (rootSibling == rootSibling->leftSibling) {
			roots.push_back(rootSibling);
		}
		while(rootSibling != minRoot->child) {
			roots.push_back(rootSibling);
			rootSibling = rootSibling->rightSibling;
		}
	}
	
	minRoot = nullptr;
	
	minRoot = roots[0];
	for (int i = 0; i < roots.size(); i++) {
		roots[i]->rightSibling = roots[(i + 1) % roots.size()];
		roots[i]->leftSibling  = roots[(i - 1) % roots.size()];
		if (roots[i]->n < minRoot->n) {
			minRoot = roots[i];
		}
	}
}

void 
FHeap::DecreaseKey(int k, int i) {
	
	std::shared_ptr<FNode> key = std::make_shared<FNode>();
	assert (k >= 0);

	if(key->parent == nullptr){
		key->n -= k;
	} else {
		key->n -= k;

		// Remove parent pointer
		std::shared_ptr<FNode> parent = key->parent;
		key->parent = nullptr;

		// Remove key from list of siblings
		std::shared_ptr<FNode> keySibling = key->rightSibling;
		while (keySibling != key) {
			if(keySibling->rightSibling == key) {
				keySibling->rightSibling = key->rightSibling;
			}
			if(keySibling->leftSibling == key) {
				keySibling->leftSibling = key->leftSibling;
			}
			keySibling = keySibling->rightSibling;
		}

		// Remove child pointer from parent, decrease rank
		if (parent->child == key) {
			parent->child = key->rightSibling;
			parent->rank--;
		}

		// Add to list of roots
		minRoot->leftSibling->rightSibling = key;
		minRoot->leftSibling = key;

		if (key->n < minRoot->n) {
			minRoot = key;
		}
	}
}

void
FHeap::Meld(std::shared_ptr<FHeap> heap) {
	std::shared_ptr<FNode> end = heap->minRoot->leftSibling;
	std::shared_ptr<FNode> mid = minRoot->leftSibling;

	minRoot->leftSibling = end;
	mid->rightSibling = heap->minRoot;

	heap->minRoot->leftSibling = mid;
	end->rightSibling = minRoot;
}


std::string FHeap::nodeInfo(std::shared_ptr<FNode> n, int rank) {
	
	std::string output = "";

	if (n->parent != nullptr && n->parent->child == n) {
		if(n->rightSibling != nullptr && n->rightSibling != n) {

			auto firstSibling = n->parent->child;
			auto sibling = n->parent->child->rightSibling;
			output += "subgraph cluster_" + std::to_string(n->n) + " { \n label=\"\"";
			output += std::to_string(firstSibling->n) + " -> " + std::to_string(firstSibling->rightSibling->n) + "\n";
			output += std::to_string(firstSibling->n) + " -> " + std::to_string(firstSibling->leftSibling->n) + "\n";

			while (sibling != firstSibling) {
				output += std::to_string(sibling->n) + " -> " + std::to_string(sibling->rightSibling->n) + "\n";
				output += std::to_string(sibling->n) + " -> " + std::to_string(sibling->leftSibling->n) + "\n";
				output += nodeInfo(n->rightSibling, rank);
				sibling = sibling->rightSibling;
			}

			output += " } ";
		}
	}

	/*if (n->parent != nullptr) {
		output = output + std::to_string(n->n) + " -> " + std::to_string(n->parent->n) + "\n";
		output += nodeInfo(n->parent, rank - 1);
	}*/
	
	if (n->child != nullptr) {		
		output = output + std::to_string(n->n) + " -> " + std::to_string(n->child->n) + "\n";
		output += nodeInfo(n->child, rank + 1);
	}

	return output;
}