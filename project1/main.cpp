#include <iostream>
#include <random>
#include <thread>
#include "FHeap.hpp"
#include "Timer.hpp"
#include "Dijkstra.hpp"
#include "BHeap.hpp"
#include "Tester.hpp"

int main() {

    Tester t;
    t.run(16);
    // Eksempel på tilfældige tal.
    /*unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 1000);
 
    for (int n=0; n<10; ++n)
        std::cout << dis(dre) << ' ';
    std::cout << '\n';
    */

    /*
    const unsigned int testsize = 1000000;
    auto testbheap = std::make_shared<BHeap>();
    Timer t1;
    t1.start();
    for(unsigned int i = 0; i < testsize; ++i) {
        testbheap->Insert(2+i,2+i);
    }
    t1.stop();
    std::cout << t1.duration().count() << std::endl;
    t1.reset();
    t1.start();
    testbheap = std::make_shared<BHeap>();
    for(unsigned int i = 0; i < testsize; ++i) {
        testbheap->Insert(2+i, testsize-i+5);
    }
    t1.stop();
    std::cout << t1.duration().count() << std::endl;

    Timer t;
    t.start();
    
    auto fheap = std::make_shared<FHeap>();

	Dijkstra f(fheap);
    f.load("test2.txt");
    f.run();
    t.stop();
   */ 
	//Dijkstra d1(fheap);
    
    //d1.sayName();
    auto bheap = std::make_shared<BHeap>();
    /*for(int i = 0; i < 40; i++) {
        bheap->Insert(2+i, 42-i);
    }
    for(int i = 0; i < 40; i++) {
        bheap->DecreaseKey(2+i,2);
    }
    for(int i = 0; i < 40; i++) {
        bheap->DeleteMin();
    }
    */ 
    //bheap->Swap();
    //std::cout << bheap->graph() << std::endl;
    /*Dijkstra d(bheap);
    d.load("test2.txt");
    d.run();
    bheap->printInformation();*/
    
    //std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}
