#include <iostream>
#include <thread>
#include "FHeap.hpp"
#include "Timer.hpp"
#include "Dijkstra.hpp"
#include "BHeap.hpp"

int main() {
    Timer t;
    t.start();

    /*auto fheap = std::make_shared<FHeap>();
	for(int i = 0; i < 10; i++) {
        fheap->Insert(10, 12-i);
    }
	fheap->DecreaseKey(10, 3);
	fheap->DeleteMin();
	fheap->FindMin();
	fheap->sayName();
    Dijkstra d1(fheap);
    */
    //d1.sayName();
    auto bheap = std::make_shared<BHeap>();
    for(int i = 0; i < 10; i++) {
        bheap->Insert(2+i, 12-i);
    }
    Dijkstra d2(bheap);
    //d2.sayName();
    std::cout << bheap->graph() << std::endl;
    bheap->DeleteMin();
    //std::cout << bheap->graph() << std::endl;
    t.stop();
    //std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}
