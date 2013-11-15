#ifndef RBTESTER_HPP_
#define RBTESTER_HPP_

#include <vector>

class RBTester {

    public:
        RBTester();
		static const int REPS = 10000;
		std::vector<int> RAN_NUMS;

        void RBTreeInsertBig(const unsigned int times);
		void RBTreeInsertSmall(const unsigned int times);
		void RBTreeDeleteMinBig(const unsigned int times);
		void RBTreeDeleteMinSmall(const unsigned int times);
        void RBTreeFindSuccSmall(const unsigned int times);
        void RBTreeFindSuccBig(const unsigned int times);

		void TestRBTree(const unsigned int highpower);

        void run(const unsigned int highpower);
};

#endif
