#include <iostream>
#include <thread>
#include "FHeap.hpp"
#include "Timer.hpp"
#include "Dijkstra.hpp"
#include "BHeap.hpp"

int main() {
    Timer t;
    t.start();
    
    auto fheap = std::make_shared<FHeap>();
	for(int i = 0; i < 10; i++) {
        fheap->Insert(10, 12-i);
    }
	//std::cout << fheap->toString("Start\n") << std::endl;
	fheap->DeleteMin();
	std::cout << fheap->toString("DeleteMin()") << std::endl;

	fheap->DecreaseKey(10, 3, nullptr, fheap->minRoot->child->leftSibling->child);
	
	std::cout << fheap->toString("DecreaseKey(10, 3)\n") << std::endl;

	std::cout << "FindMin()" << std::endl << fheap->FindMin() << std::endl << std::endl ;
	fheap->sayName();
	Dijkstra d1(fheap);
    
    //d1.sayName();
    auto bheap = std::make_shared<BHeap>();
    for(int i = 0; i < 40; i++) {
        bheap->Insert(2+i, 42-i);
    }
    Dijkstra d2(bheap);
    //d2.sayName();
    //std::cout << bheap->graph() << std::endl;
    //bheap->DeleteMin();
    bheap->Swap();
    std::cout << bheap->graph() << std::endl;
    t.stop();
    //std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}
