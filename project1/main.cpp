#include <iostream>
#include <random>
#include <thread>
#include "FHeap.hpp"
#include "Timer.hpp"
#include "Dijkstra.hpp"
#include "BHeap.hpp"

int main() {

    // Eksempel på tilfældige tal.
    /*unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 1000);
 
    for (int n=0; n<10; ++n)
        std::cout << dis(dre) << ' ';
    std::cout << '\n';
    */


    Timer t;
    t.start();
    
    auto fheap = std::make_shared<FHeap>();
	for(int i = 0; i < 20; i++) {
        fheap->Insert(i + 5, 120-i);
    }
	std::cout << fheap->toString("Start\n") << std::endl;
	fheap->DeleteMin();
	std::cout << fheap->toString("DeleteMin()") << std::endl;

	fheap->DecreaseKey(8, 3);
	std::cout << fheap->toString("DecreaseKey(8, 3)\n") << std::endl;

	std::cout << "FindMin()" << std::endl << fheap->FindMin() << std::endl << std::endl ;
	fheap->sayName();
	Dijkstra d1(fheap);
    
    //d1.sayName();
    auto bheap = std::make_shared<BHeap>();
    /*for(int i = 0; i < 40; i++) {
        bheap->Insert(2+i, 42-i);
    }
    //d2.sayName();
    //std::cout << bheap->graph() << std::endl;
    for(int i = 0; i < 40; i++) {
        std::cout << i << std::endl;
        bheap->DeleteMin();
    }
    */
    //bheap->Swap();
    //std::cout << bheap->graph() << std::endl;
    Dijkstra d(bheap);
    d.load("test.txt");
    d.run();
    t.stop();
    //std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}