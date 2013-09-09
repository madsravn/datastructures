#include <iostream>
#include <thread>
#include "FHeap.hpp"
#include "Timer.hpp"

int main() {
    Timer t;
    FHeap fheap;
    t.start();
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);
    t.stop();
    std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}
