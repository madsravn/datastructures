#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "FHeap.hpp"
#include "BHeap.hpp"
#include "Dijkstra.hpp"

class Tester {

    public:
        Tester();
		static const int REPS = 10000;
		std::vector<int> RAN_NUMS;

		void TestBHeap(const unsigned int highpower);
		void TestFHeap(const unsigned int highpower);

        void BHeapInsertBig(const unsigned int times);
		void BHeapInsertSmall(const unsigned int times);
		void BHeapDeleteMinBig(const unsigned int times);
		void BHeapDeleteMinSmall(const unsigned int times);
		void BHeapDecreaseKeySmall(const unsigned int times);        
		void BHeapDecreaseKeyBig(const unsigned int times);

        void FHeapInsertBig(const unsigned int times);
        void FHeapInsertSmall(const unsigned int times);
        void FHeapDeleteMinBig(const unsigned int times);
        void FHeapDeleteMinSmall(const unsigned int times);
        void FHeapDecreaseKeySmall(const unsigned int times);        
		void FHeapDecreaseKeyBig(const unsigned int times);
        
        void run(const unsigned int highpower);

};

#endif
