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
    return forest[0].root->n;
}

void
FHeap::Insert(int i) {
	auto heap = std::make_shared<FHeap>();
	heap->Insert(i);
	Meld(heap);
}

void
FHeap::DeleteMin() {

}

void 
FHeap::DecreaseKey(int k, int i) {

}

void
FHeap::Meld(std::shared_ptr<FHeap> heap) {
	
}
