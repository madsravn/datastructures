#ifndef VEBTESTER_HPP_
#define VEBTESTER_HPP_

#include <vector>

class VEBTester {

    public:
        VEBTester();
		static const int REPS = 10000;
		std::vector<int> RAN_NUMS, UPS, DOWNS;

        void VEBTreeInsert(const unsigned int times, std::vector<int> build_range, std::vector<int> update_range);

        void VEBTreeInsertBig(const unsigned int times);
		void VEBTreeInsertSmall(const unsigned int times);
		void VEBTreeDeleteMinBig(const unsigned int times);
		void VEBTreeDeleteMinSmall(const unsigned int times);
        void VEBTreeFindSuccBig(const unsigned int times);
		void VEBTreeFindSuccSmall(const unsigned int times);
        void VEBTreeFindSuccRandom(const unsigned int times);
        void VEBTreeDeleteMinRandom(const unsigned int times);
        void VEBTreeInsertRandom(const unsigned int times);


		void TestVEBTree(const unsigned int highpower);

        void run(const unsigned int highpower);
};

#endif
