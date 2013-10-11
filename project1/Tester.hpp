#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "FHeap.hpp"
#include "BHeap.hpp"
#include "Dijkstra.hpp"

class Tester {

    public:
        Tester();

		static const int REPS = 1;
		std::vector<int> RAN_NUMS;

		void TestBHeap(const unsigned int highpower);
		void TestFHeap(const unsigned int highpower);


        // Big = descending
        void BHeapInsertBig(const unsigned int times);
        // Small = ascending
		void BHeapInsertSmall(const unsigned int times);

		void BHeapInsertRand(const unsigned int times);
		void BHeapDeleteMinBig(const unsigned int times);
		void BHeapDeleteMinSmall(const unsigned int times);
		void BHeapDecreaseKey(const unsigned int times);        
		void BHeapDecreaseKeyWorst(const unsigned int times);

		// Big = descending
        void FHeapInsertBig(const unsigned int times);
        // Small = ascending
        void FHeapInsertSmall(const unsigned int times);

        void FHeapDeleteMinBig(const unsigned int times);
        void FHeapDeleteMinSmall(const unsigned int times);
		void FHeapDecreaseKey(const unsigned int times);
        
        
        void run(const unsigned int highpower);

};

#endif
