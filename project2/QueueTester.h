#ifndef QUEUETESTER_HPP_
#define QUEUETESTER_HPP_

#include <vector>
#include "IQueue.hpp"

class QueueTester {

    public:
        QueueTester(std::shared_ptr<IQueue>);
		static const int REPS = 10000;
		std::vector<int> RAN_NUMS, UPS, DOWNS;
		std::shared_ptr<IQueue> queue;

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

        void run(const unsigned int highpower);
};

#endif
