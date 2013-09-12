#include "FHeap.hpp"
#include "FNode.hpp"

FHeap::FHeap() {

}

void 
FHeap::MakeHeap() {
	forest[0] = FTree();
}

void
FHeap::sayName() {
    std::cout << "I am FHeap" << std::endl;
}

int
FHeap::FindMin() {
    return forest[0].root->n; //TODO: måske?
}

void
FHeap::Insert(int k, int priority) {
	auto heap = std::make_shared<FHeap>();
	heap->Insert(k, priority);
	Meld(heap);
}

void
FHeap::DeleteMin() {
/*	for (int i = 0; i < forest.size; i++) {
		
	}*/
}

void 
FHeap::DecreaseKey(int k, int i) {

}

void
FHeap::Meld(std::shared_ptr<FHeap> heap) {
	
}
