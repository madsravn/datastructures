#include <iostream>
#include <thread>
#include "Timer.hpp"

int main() {
    Timer t;
    t.start();
    std::cout << "Hello friend." << std::endl;
     std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
    t.stop();
    std::cout << "It took: " << t.duration().count() << " milliseconds" << std::endl;

    return 0;
}
