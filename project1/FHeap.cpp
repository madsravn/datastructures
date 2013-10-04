#include "FHeap.hpp"
#include "FNode.hpp"
#include <cassert>
#include <string>

FHeap::FHeap() {

}

std::string FHeap::toString(std::string label) {
	std::shared_ptr<FNode> tempNode = std::make_shared<FNode>();
	tempNode->key = -1;
	tempNode->priority = -1;
	tempNode->child = minRoot;
	minRoot->parent = tempNode;

	std::string output = "";
	output += "digraph { \n";
	output += "rankdir=TB;";
	output += "label=\"" + label + " \"; labelloc=top;";
	output += nodeInfo(minRoot, 0);
	output += "}\n";
	minRoot->parent = nullptr;

	return output;
}

bool
	FHeap::empty() {
		if (minRoot == nullptr) {
			return true;
		} else {
			return false;
		}
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
		return minRoot->key;
}

std::shared_ptr<INode> FHeap::Insert(int k, int priority) {
	if (minRoot != nullptr) {
		std::shared_ptr<FHeap> heap = std::make_shared<FHeap>();
		heap->Insert(k, priority);
		return Meld(heap);
	} else {
		std::shared_ptr<FNode> node = std::make_shared<FNode>(k, priority);
		node->child = nullptr;
		node->parent = nullptr;
		node->leftSibling = node;
		node->rightSibling = node;
		node->rank = 0;
		node->marked = false;
		minRoot = node;
		return node;
	}
}

int	FHeap::DeleteMin() {

	std::cout << toString("DeleteMin") << std::endl << std::endl;

	int ret = 1;

	if (minRoot != nullptr) {

		ret = minRoot->key;

		// If last node, return ret
		if (minRoot->child == nullptr && minRoot->parent == nullptr && minRoot->leftSibling == minRoot && minRoot->rightSibling == minRoot) {
			minRoot = nullptr;
			return ret;
		}

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

			std::shared_ptr<FNode> sibling = rootSibling->rightSibling;

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
			if (roots[i]->priority < minRoot->priority) {
				minRoot = roots[i];
			}
		}

		// Checkpoint: Rigtige Nodes i roots, med pointers til siblings, og korrekt minRoot.


		// Link nodes by rank
		std::vector<std::list<std::shared_ptr<FNode>>> buckets = bucketSort(minRoot);

		for (int i = 0; i < buckets.size(); i++) {
			std::list<std::shared_ptr<FNode>> bucket = buckets.at(i);
			if(bucket.size() > 1) {
				for (std::list<std::shared_ptr<FNode>>::iterator bucketi = buckets.at(i).begin(); bucketi != (buckets.at(i).end()) ; ++bucketi) {



					std::shared_ptr<FNode> parentNode;
					std::shared_ptr<FNode> childNode;

					if (bucketi == buckets.at(i).end()) {
						break;
					}

					std::shared_ptr<FNode> firstElement = *bucketi;
					++bucketi;
					if (bucketi == buckets.at(i).end()) {
						break;
					}
					std::shared_ptr<FNode> secondElement = *bucketi;

					if(firstElement->priority <= secondElement->priority) {
						// make bucketi parent of bucketi + 1
						parentNode = firstElement;
						childNode = secondElement;
					} else {
						// make bucketi + 1 parent of bucketi
						parentNode = secondElement;
						childNode = firstElement;
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
						if(parentNode->child->priority > childNode->priority) {
							parentNode->child = childNode;
						}

					} else {
						parentNode->child = childNode;
						childNode->parent = parentNode;

						childNode->leftSibling = childNode;
						childNode->rightSibling = childNode;
					}					

					parentNode->rank++;
					childNode->marked = false;

					// move bucketi to new position in buckets
					if (buckets.size() <= parentNode->rank) {
						buckets.resize(parentNode->rank + 1);
					}
					auto parentRank = parentNode->rank;
					buckets.at(parentNode->rank).push_back(parentNode);					
					bucket.remove(parentNode);
				}
			}
			buckets.at(i) = bucket;
		}
	}

	std::cout << toString("DeleteMin(" + std::to_string(ret) + ")") << std::endl << std::endl;

	return ret;
}

void FHeap::DecreaseKey(std::shared_ptr<INode> keyNode, int i) {

	std::shared_ptr<FNode> key = std::static_pointer_cast<FNode>(keyNode);

	key->priority -= i;

	if(key->parent != nullptr){
		// Remove parent pointer
		std::shared_ptr<FNode> parent = key->parent;
		key->parent = nullptr;

		// Remove child pointer from parent, decrease rank
		if(key->rightSibling == key) {
			parent->child = nullptr;
		} else {
			parent->child = key->rightSibling;
		}
		parent->rank--;

		// Remove key from list of siblings
		key->rightSibling->leftSibling = key->leftSibling;
		key->leftSibling->rightSibling = key->rightSibling;			
		key->rightSibling = nullptr;
		key->leftSibling = nullptr;

		// Add to list of roots
		key->leftSibling = minRoot->leftSibling;
		key->rightSibling = minRoot;
		key->leftSibling->rightSibling = key;
		key->rightSibling->leftSibling = key;

		// If this is smaller than current minRoot, move pointer
		if (key->priority < minRoot->priority) {
			minRoot = key;
		}

		cascadingCuts(parent);
	}
}

void FHeap::cascadingCuts(std::shared_ptr<FNode> node) {

	if (node->parent == nullptr) return;

	std::shared_ptr<FNode> parent = node->parent;

	if(!parent->marked) {
		// Mark parent
		parent->marked = true;

	} else {
		// Cut edge to parent
		node->parent = nullptr;

		// Redirect child pointer
		if (node->rightSibling == node) {
			parent->child = nullptr;
		} else {
			parent->child = node->rightSibling;
		}

		// Remove child from sibling list
		node->rightSibling->leftSibling = node->leftSibling;
		node->leftSibling->rightSibling = node->rightSibling;
		node->rightSibling = nullptr;
		node->leftSibling = nullptr;

		// Add child to list of roots
		node->rightSibling = minRoot;
		node->leftSibling = minRoot->leftSibling;
		node->rightSibling->leftSibling = node;
		node->leftSibling->rightSibling = node;
		if (node->priority < minRoot->priority) {
			minRoot = node;
		}

		// Decrease rank
		parent->rank--;

		// Cascade
		cascadingCuts(parent);
	}
}

std::vector<std::list<std::shared_ptr<FNode>>> FHeap::bucketSort(std::shared_ptr<FNode> root) {

	std::vector<std::shared_ptr<FNode>> nodes;

	int max = 0;
	std::shared_ptr<FNode> sibling = root->rightSibling;
	nodes.push_back(root);

	while(root != sibling) {
		nodes.push_back(sibling);
		max = std::max(max, sibling->rank);
		sibling = sibling->rightSibling;
	}

	std::vector<std::list<std::shared_ptr<FNode>>> bucketList;

	for (int i = 0; i <= max; i++) {
		bucketList.insert(bucketList.end(), std::list<std::shared_ptr<FNode>>());
	}

	// Add nodes to buckets
	for (int i = 0; i < nodes.size(); i++) {
		std::shared_ptr<FNode> currentNode = nodes.at(i);		
		bucketList.at(currentNode->rank).push_back(currentNode);
	}

	return bucketList;
}

std::shared_ptr<FNode> FHeap::Meld(std::shared_ptr<FHeap> heap) {
	std::shared_ptr<FNode> end = heap->minRoot->leftSibling;
	std::shared_ptr<FNode> mid = minRoot->leftSibling;

	minRoot->leftSibling = end;
	heap->minRoot->leftSibling = mid;

	mid->rightSibling = heap->minRoot;
	end->rightSibling = minRoot;

	if (heap->minRoot->priority < minRoot->priority) {
		minRoot = heap->minRoot;
	}

	return heap->minRoot;
}


std::string FHeap::nodeInfo(std::shared_ptr<FNode> n, int rank) {

	bool DEBUGOUTPUT = true;

	std::cout << n->key << std::endl;

	std::string output = "";








	if (n->parent != nullptr && n->parent->child == n) {

		if(n->rightSibling != nullptr) {

			std::string graphRank = "{ rank=same; ";


			if (n->rightSibling != n) {

				auto firstSibling = n->parent->child;
				auto sibling = firstSibling->rightSibling;

				output += std::to_string(firstSibling->key) + " -> " + std::to_string(firstSibling->rightSibling->key) + "[ label=\"right\" ]" + "\n";
				output += std::to_string(firstSibling->key) + " -> " + std::to_string(firstSibling->leftSibling->key) + "[ label=\"left\" ]" + "\n";
				graphRank +=  std::to_string(firstSibling->key);

				while (sibling != firstSibling) {
					output += std::to_string(sibling->key) + " -> " + std::to_string(sibling->rightSibling->key) + "[ label=\"right\" ]" + "\n" ;
					output += std::to_string(sibling->key) + " -> " + std::to_string(sibling->leftSibling->key) + "[ label=\"left\" ]" + "\n";
					output += nodeInfo(sibling, rank);

					graphRank += ", " + std::to_string(sibling->key);

					sibling = sibling->rightSibling;
				}

			} else {
				output += std::to_string(n->key) + " -> " + std::to_string(n->rightSibling->key) + "[ label=\"right\" ]" + "\n" ;
				output += std::to_string(n->key) + " -> " + std::to_string(n->leftSibling->key) + "[ label=\"left\" ]" + "\n";
			}

			graphRank += " }\n";
			output += graphRank;
		}





	}

	if (n->child != nullptr) {		
		output = output + std::to_string(n->key) + " -> " + std::to_string(n->child->key) + "[ label=\"child\" ]" + "\n";
		output = output + std::to_string(n->child->key) + " -> " +  std::to_string(n->key) + "[ label=\"parent\" ]" + "\n";
		output += nodeInfo(n->child, rank + 1);
	}

	std::string label = std::to_string(n->key) + " [label = \"" + std::to_string(n->key) + ", " + std::to_string(n->priority)  + "\"]\n";
	output += label;

	return output;
}
