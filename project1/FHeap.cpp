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
	output += "rankdir=TB;";
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
			std::shared_ptr<FNode> node = std::make_shared<FNode>(k, priority);
			node->child = nullptr;
			node->parent = nullptr;
			node->leftSibling = node;
			node->rightSibling = node;
			node->rank = 0;
			node->marked = true; // Dunno wtf
			minRoot = node;
		}
}

int	FHeap::DeleteMin() {

	int ret = 1;

		if (minRoot != nullptr) {

			ret = minRoot->n;

			std::shared_ptr<FNode> root = minRoot;

			std::vector<std::shared_ptr<FNode>> roots;

			// Delete root
			std::shared_ptr<FNode> rootSibling = minRoot->rightSibling;
			if (rootSibling == minRoot) {
				minRoot->parent = nullptr;
				minRoot->leftSibling = nullptr;
				minRoot->rightSibling = nullptr;
			}


			// Add other roots to list
			while(rootSibling != minRoot) {
				roots.push_back(rootSibling);

				auto sibling = rootSibling->rightSibling;

				// Reset sibling and parent pointers
				rootSibling->rightSibling = nullptr;
				rootSibling->leftSibling = nullptr;
				rootSibling->parent = nullptr;

				rootSibling = sibling;


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
				roots[i]->rightSibling = roots[(i + 1 + roots.size()) % roots.size()];
				roots[i]->leftSibling  = roots[(i - 1 + roots.size()) % roots.size()];
				if (roots[i]->n < minRoot->n) {
					minRoot = roots[i];
				}
			}

			// Checkpoint: Rigtige Nodes i roots, med pointers til siblings, og korrekt minRoot.


			// Link nodes by rank
			std::vector<std::vector<std::shared_ptr<FNode>>> buckets = bucketSort(minRoot);

			for (int i = 0; i < buckets.size(); i++) {
				std::vector<std::shared_ptr<FNode>> bucket = buckets.at(i);
				if(bucket.size() > 1) {
					for (int bucketi = 0; bucketi + 1 < bucket.size(); bucketi += 2) {

						std::shared_ptr<FNode> parentNode;
						std::shared_ptr<FNode> childNode;

						if(bucket.at(bucketi)->n <= bucket.at(bucketi + 1)->n) {
							// make bucketi parent of bucketi + 1
							parentNode = bucket.at(bucketi);
							childNode = bucket.at(bucketi + 1);
						} else {
							// make bucketi + 1 parent of bucketi
							parentNode = bucket.at(bucketi);
							childNode = bucket.at(bucketi + 1);
						}

						// Remove childNode from siblings
						if (childNode->rightSibling != childNode) {
							childNode->rightSibling->leftSibling = childNode->leftSibling;
							childNode->leftSibling->rightSibling = childNode->rightSibling;
						}
						childNode->rightSibling = nullptr;
						childNode->leftSibling = nullptr;

						// If parentNode has children, add childNode to list
						if(parentNode->child != nullptr) {

							childNode->rightSibling = parentNode->child;
							childNode->leftSibling = parentNode->child->leftSibling;	
							
							// Add childNode to list of children
							parentNode->child->leftSibling->rightSibling = childNode;
							parentNode->child->leftSibling = childNode;	
							childNode->parent = parentNode;

							// If new child is smallest child, change parent's child pointer
							if(parentNode->child->n > childNode->n) {
								parentNode->child = childNode;
							}

						} else {
							parentNode->child = childNode;
							childNode->parent = parentNode;

							childNode->leftSibling = childNode;
							childNode->rightSibling = childNode;
						}					

						parentNode->rank++;

						// move bucketi to new position in buckets
						if (buckets.size() <= parentNode->rank) {
							buckets.resize(parentNode->rank + 1);
						}
						buckets.at(parentNode->rank).push_back(parentNode);


					}		
				}
			}
		}
		return ret;
}

void 
	FHeap::DecreaseKey(int k, int i) {

		std::shared_ptr<FNode> key = std::make_shared<FNode>(); // TODO: Brug en rigtig node

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




			//TODO: Cascading cuts
		}
}

std::vector<std::vector<std::shared_ptr<FNode>>> FHeap::bucketSort(std::shared_ptr<FNode> root) {

	std::vector<std::shared_ptr<FNode>> nodes;

	int max = 0;
	std::shared_ptr<FNode> sibling = root->rightSibling;
	nodes.push_back(root);

	while(root != sibling) {
		nodes.push_back(sibling);
		max = std::max(max, sibling->rank);
		sibling = sibling->rightSibling;
	}

	std::vector<std::vector<std::shared_ptr<FNode>>> bucketList;

	for (int i = 0; i <= max; i++) {
		bucketList.push_back(std::vector<std::shared_ptr<FNode>>());
	}

	// Add nodes to buckets
	for (int i = 0; i < nodes.size(); i++) {
		std::shared_ptr<FNode> currentNode = nodes.at(i);		
		bucketList.at(currentNode->rank).push_back(currentNode);
	}

	return bucketList;
}

void
	FHeap::Meld(std::shared_ptr<FHeap> heap) {
		std::shared_ptr<FNode> end = heap->minRoot->leftSibling;
		std::shared_ptr<FNode> mid = minRoot->leftSibling;

		minRoot->leftSibling = end;
		heap->minRoot->leftSibling = mid;

		mid->rightSibling = heap->minRoot;
		end->rightSibling = minRoot;

		if (heap->minRoot->n < minRoot->n) {
			minRoot = heap->minRoot;
		}
}


std::string FHeap::nodeInfo(std::shared_ptr<FNode> n, int rank) {

	std::cout << n->n << std::endl;

	std::string output = "";

	if (n->parent != nullptr && n->parent->child == n) {

		if(n->rightSibling != nullptr) {

			std::string graphRank = "{ rank=same; ";


			if (n->rightSibling != n) {

				auto firstSibling = n->parent->child;
				auto sibling = firstSibling->rightSibling;

				output += std::to_string(firstSibling->n) + " -> " + std::to_string(firstSibling->rightSibling->n) + "[ label=\"right\" ]" + "\n";
				output += std::to_string(firstSibling->n) + " -> " + std::to_string(firstSibling->leftSibling->n) + "[ label=\"left\" ]" + "\n";
				graphRank +=  std::to_string(firstSibling->n);

				while (sibling != firstSibling) {
					output += std::to_string(sibling->n) + " -> " + std::to_string(sibling->rightSibling->n) + "[ label=\"right\" ]" + "\n" ;
					output += std::to_string(sibling->n) + " -> " + std::to_string(sibling->leftSibling->n) + "[ label=\"left\" ]" + "\n";
					std::cout << "Going to rightSibling" << std::endl;
					output += nodeInfo(sibling, rank);

					graphRank += ", " + std::to_string(sibling->n);


					sibling = sibling->rightSibling;
				}

			} else {
				output += std::to_string(n->n) + " -> " + std::to_string(n->rightSibling->n) + "[ label=\"rightSibling\" ]" + "\n" ;
				output += std::to_string(n->n) + " -> " + std::to_string(n->leftSibling->n) + "[ label=\"leftSibling\" ]" + "\n";
			}

			graphRank += " }\n";
			output += graphRank;
		}
	}

	if (n->child != nullptr) {		
		output = output + std::to_string(n->n) + " -> " + std::to_string(n->child->n) + "[ label=\"child\" ]" + "\n";
		output = output + std::to_string(n->child->n) + " -> " +  std::to_string(n->n) + "[ label=\"parent\" ]" + "\n";
		std::cout << "Going to child" << std::endl;
		output += nodeInfo(n->child, rank + 1);
		std::cout << "Going back to parent" << std::endl;
	}

	return output;
}
