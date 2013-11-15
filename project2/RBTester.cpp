#include "RBTester.h"
#include "RBTree.h"
#include "Timer.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>

RBTester::RBTester() {}

void
RBTester::RBTreeInsertBig(const unsigned int times) {
    auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; ++i) {
        tree->insert(i+2);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
		tree->comparisons = 0;
        t.start();
		tree->insert(i+2);
		t.stop();
		comparisons += tree->comparisons;

		tree->deleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
RBTester::RBTreeInsertSmall(const unsigned int times) {
    auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times + REPS; i > REPS; --i) {
        tree->insert(i+2);
    }
	
	Timer t;
    t.start();
	unsigned int comparisons = 0;
    for(unsigned i = 0; i < REPS; ++i) {
		tree->comparisons = 0;
        t.start();
		tree->insert(i+2);
		t.stop();
		comparisons += tree->comparisons;

		tree->deleteMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void RBTester::RBTreeDeleteMinBig(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times; i > 0; --i) {
        tree->insert(i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; --i) {
		tree->comparisons = 0;
		t.start();
		tree->deleteMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->insert(i+2);
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void RBTester::RBTreeDeleteMinSmall(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times; i > 0; --i) {
        tree->insert(i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = 0; i < REPS; ++i) {
		tree->comparisons = 0;
		t.start();
		tree->deleteMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->insert(i+2);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void RBTester::RBTreeFindSuccSmall(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times; i > 0; --i) {
        tree->insert(i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = 0; i < REPS; ++i) {
		tree->comparisons = 0;
		t.start();
		tree->predecessor(i);
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void RBTester::RBTreeFindSuccBig(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times; i > 0; --i) {
        tree->insert(i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0 ; --i) {
		tree->comparisons = 0;
		t.start();
		tree->predecessor(i);
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}



void RBTester::TestRBTree(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing RBTree <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	
	i = 4;
    power = 2;

	std::cout << "\nTesting RBTreeInsertBig\n" << std::endl;
	
	while(power <= highpower) {
        RBTreeInsertBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting RBTreeInsertSmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeInsertSmall(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting RBTreeDeleteMinBig\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting RBTreeDeleteMinSmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting VEBTreeFindSuccBig\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeFindSuccBig(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting VEBTreeFindSuccSmall\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeFindSuccSmall(i);
        power++;
        i = pow(2,power);
    }


}

void
RBTester::run(const unsigned int highpower) {	

	unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 10000);
 
	for (int n = 0; n < (REPS * 2) + pow(2, highpower); ++n) {
		
		RAN_NUMS.push_back(dis(dre));
	}

	TestRBTree(highpower);
}
