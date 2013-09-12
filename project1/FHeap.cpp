#include "FHeap.hpp"
#include "FNode.hpp"

FHeap::FHeap() {

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
		auto heap = std::make_shared<FHeap>();
		Meld(heap);
	} else {
		auto node = std::make_shared<FNode>(priority);
		minRoot = node;
	}
}

void
FHeap::DeleteMin() {
	auto root = minRoot;
	
	std::vector<std::shared_ptr<FNode>> roots;

	// Add other roots to list
	std::shared_ptr<FNode> rootSibling = minRoot->rightSibling;
	while(rootSibling != minRoot) {
		roots.push_back(rootSibling);
		rootSibling = rootSibling->rightSibling;
	}

	// Add deleted node's children to list
	roots.push_back(minRoot->child);
	rootSibling = minRoot->child->rightSibling;
	while(rootSibling != minRoot->child) {
		roots.push_back(rootSibling);
		rootSibling = rootSibling->rightSibling;
	}

	minRoot = nullptr;

	std::vector<std::shared_ptr<FNode>> finalRoots;
	
	for (int i = 0; i < finalRoots.size(); i++) {
		finalRoots[i]->rightSibling = finalRoots[(i + 1) % finalRoots.size()];
		finalRoots[i]->leftSibling  = finalRoots[(i - 1) % finalRoots.size()];
	}
}

void 
FHeap::DecreaseKey(int k, int i) {
	std::shared_ptr<FNode> key = std::make_shared<FNode>();
	
	if(k < 0) {
		//TODO: SÅ GÅR DET GALT
	}

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

	std::vector<std::shared_ptr<FNode>> roots;

	std::shared_ptr<FNode> rootSibling = minRoot->rightSibling;

	// Add this heap's roots to list
	while (rootSibling != minRoot) {
		roots.push_back(rootSibling);
		rootSibling = rootSibling->rightSibling;
	}

	// Add other heap's roots to list
	roots.push_back(heap->minRoot);
	rootSibling = heap->minRoot->rightSibling;
	while(rootSibling != heap->minRoot) {
		roots.push_back(rootSibling);
		rootSibling = rootSibling->rightSibling;
	}

	rootSibling = heap->minRoot->rightSibling;
	while(rootSibling != heap->minRoot) {
		roots.push_back(rootSibling);
		rootSibling = rootSibling->rightSibling;
	}

	for (int i = 0; i < roots.size(); i++) {
		roots[i]->rightSibling = roots[(i + 1) % roots.size()];
		roots[i]->leftSibling  = roots[(i - 1) % roots.size()];
	}
}