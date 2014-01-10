#ifndef TESTER_HPP_
#define TESTER_HPP_

#include <vector>

class Tester {

    public:
        Tester();
		static const int REPS = 100000;
		std::vector<int> RAN_NUMS, UPS, DOWNS;

		void PartialUpdateTop(const unsigned int times);
		void PartialUpdateMid(const unsigned int times);
        void PartialUpdateBottom(const unsigned int times);

		void FullyUpdateTop(const unsigned int times);
		void FullyUpdateMid(const unsigned int times);
        void FullyUpdateBottom(const unsigned int times);

		void PartialQueryTop(const unsigned int times);        
		void PartialQueryMid(const unsigned int times);
        void PartialQueryBottom(const unsigned int times);

		void FullyQueryTop(const unsigned int times);        
		void FullyQueryMid(const unsigned int times);
        void FullyQueryBottom(const unsigned int times);

		void TestRetro(const unsigned int highpower);

        void run(const unsigned int highpower);
};

#endif
