#include "Tester.hpp"
#include "Timer.hpp"
#include <cmath>

Tester::Tester() {}

void
Tester::BHeapInsertBig(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();
    Timer t;
    t.start();
    for(unsigned i = times; i > 0; --i) {
        bheap->Insert(i+2,i+2);
    }
    t.stop();
    std::cout << "BHeapInsertBig " << times << " took " << t.duration().count() << " ms" << std::endl;
}

void
Tester::BHeapInsertSmall(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();
    Timer t;
    t.start();
    for(unsigned i = 0; i < times; ++i) {
        bheap->Insert(i+2,i+2);
    }
    t.stop();
    std::cout << "BHeapInsertSmall " << times << " took " << t.duration().count() << " ms" << std::endl;
}


void
Tester::run(const unsigned int highpower) {
    unsigned int i = 2;
    int power = 1;
    while(true) {
        BHeapInsertBig(i);
        BHeapInsertSmall(i);



        if(power == highpower) {
            power = 0;
        }
        power++;
        i = pow(2,power);
    }
}
