#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "FHeap.hpp"
#include "BHeap.hpp"
#include "Dijkstra.hpp"

class Tester {

    public:
        Tester();
        // Big = descending
        void BHeapInsertBig(const unsigned int times);
        // Small = ascending
        void BHeapInsertSmall(const unsigned int times);
        /*void BHeapInsertRand(const unsigned int times);
        void BHeapDeleteMinBig(const unsigned int times);
        void BHeapDeleteMinSmall(const unsigned int times);
        void BHeapDeleteMinRand(const unsigned int times);
        void BHeapDecreaseKey(const unsigned int times);
        */
        void run(const unsigned int highpower);

};

#endif
