#ifndef QUEUETESTER_HPP_
#define QUEUETESTER_HPP_

#include <vector>
#include "IQueue.hpp"

class QueueTester {

    public:
        QueueTester(int t);
		static const int REPS = 100000;
		std::vector<int> RAN_NUMS, UPS, DOWNS;
		int type;

		void QueueInsertBig(const unsigned int times);
		void QueueInsertSmall(const unsigned int times);
        void QueueInsertRandom(const unsigned int times);

		void QueueDeleteMinBig(const unsigned int times);
		void QueueDeleteMinSmall(const unsigned int times);
        void QueueDeleteMinRandom(const unsigned int times);

		void QueueDecreaseKeySmall(const unsigned int times);        
		void QueueDecreaseKeyBig(const unsigned int times);
        void QueueDecreaseKeyRandom(const unsigned int times);

		void TestQueue(const unsigned int highpower);
		std::shared_ptr<IQueue> MakeQueue();


        void run(const unsigned int highpower);
};

#endif
