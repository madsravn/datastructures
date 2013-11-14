#ifndef TESTER_HPP_
#define TESTER_HPP_

#include <vector>

class VEBTester {

    public:
        VEBTester();
		static const int REPS = 10000;
		std::vector<int> RAN_NUMS;

        void VEBTreeInsertBig(const unsigned int times);
		void VEBTreeInsertSmall(const unsigned int times);
		void VEBTreeDeleteMinBig(const unsigned int times);
		void VEBTreeDeleteMinSmall(const unsigned int times);

		void TestVEBTree(const unsigned int highpower);

        void run(const unsigned int highpower);
};

#endif