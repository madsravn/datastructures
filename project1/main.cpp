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
    Dijkstra d1(fheap);
    d1.sayName();
    auto bheap = std::make_shared<BHeap>();
    Dijkstra d2(bheap);
    d2.sayName();

    t.stop();
    std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}
