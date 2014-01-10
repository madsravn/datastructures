#ifndef TESTER_HPP_
#define TESTER_HPP_

#include <vector>
#include <map>

class Tester {

    public:
        Tester();
		static const int REPS = 8;
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
		void TestRetroCopy(const unsigned int highpower);

		void printMap(std::map<int, int> pmap, std::map<int, int> rmap);
        void run(const unsigned int highpower);
};

#endif
