#include "VEBTester.h"
#include "VEBTree.h"
#include "Timer.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>

VEBTester::VEBTester() {}

void
VEBTester::VEBTreeInsertBig(const unsigned int times) {
    auto tree = std::make_shared<VEBTree>();    
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

		tree->delMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
VEBTester::VEBTreeInsertSmall(const unsigned int times) {
    auto tree = std::make_shared<VEBTree>();    
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

		tree->delMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeDeleteMinBig(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = times; i > 0; --i) {
        tree->insert(i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; --i) {
		tree->comparisons = 0;
		t.start();
		tree->delMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->insert(i+2);
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeDeleteMinSmall(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = times; i > 0; --i) {
        tree->insert(i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = 0; i < REPS; ++i) {
		tree->comparisons = 0;
		t.start();
		tree->delMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->insert(i+2);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}


void VEBTester::TestVEBTree(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing VEBTree <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	
	i = 2;
    power = 1;

	std::cout << "\nTesting VEBTreeInsertBig\n" << std::endl;
	
	while(power <= highpower) {
        VEBTreeInsertBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting VEBTreeInsertSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        VEBTreeInsertSmall(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting VEBTreeDeleteMinBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        VEBTreeDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting VEBTreeDeleteMinSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        VEBTreeDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }
}

void
VEBTester::run(const unsigned int highpower) {	

	unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 10000);
 
	for (int n = 0; n < (REPS * 2) + pow(2, highpower); ++n) {
		
		RAN_NUMS.push_back(dis(dre));
	}

	TestVEBTree(highpower);
}
