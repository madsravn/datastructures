#include "RBTester.h"
#include "RBTree.h"
#include "Timer.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

RBTester::RBTester() {}

void
RBTester::RBTreeInsertBig(const unsigned int times) {
    auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->insert(i+1);
    }

	//std::cout << tree->toString("tree");

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times; i < REPS + times; i++) {
		tree->comparisons = 0;
        t.start();
		tree->insert(i+1);
		t.stop();
		comparisons += tree->comparisons;
		//std::cout << tree->toString("after insert");

		tree->deleteMin();
		//std::cout << tree->toString("after deleteMin");
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << float(comparisons) << " comparisons" << std::endl;
}

void
RBTester::RBTreeInsertSmall(const unsigned int times) {
    auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times + REPS; i > REPS; i--) {
        tree->insert(i+1);
    }
	
	Timer t;
    t.start();
	unsigned int comparisons = 0;
    for(unsigned i = REPS; i > 0; i--) {
		tree->comparisons = 0;
        t.start();
		tree->insert(i+1);
		t.stop();
		comparisons += tree->comparisons;

		tree->deleteMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << float(comparisons) << " comparisons" << std::endl;
}

void RBTester::RBTreeDeleteMinBig(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->insert(i+1);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS; i++) {
		tree->comparisons = 0;
		t.start();
		tree->deleteMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->insert(i+1);
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << float(comparisons) << " comparisons" << std::endl;
}

void RBTester::RBTreeDeleteMinSmall(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times + REPS; i > REPS; i--) {
        tree->insert(i+1);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; i--) {
		tree->comparisons = 0;
		t.start();
		tree->deleteMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->insert(i+1);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << float(comparisons) << " comparisons" << std::endl;
}

void RBTester::RBTreeFindSuccSmall(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = times + REPS; i > REPS; i--) {
        tree->insert(i+1);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; i--) {
		tree->comparisons = 0;
		t.start();
		tree->search(i);
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << float(comparisons) << " comparisons" << std::endl;
}

void RBTester::RBTreeFindSuccBig(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->insert(i+1);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
		t.start();
		tree->search(i);
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << float(comparisons) << " comparisons" << std::endl;
}

void RBTester::RBTreeFindSuccRandom(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->insert(RAN_NUMS.at(i));
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
		t.start();
		tree->predecessor(RAN_NUMS.at(i));
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void RBTester::RBTreeDeleteMinRandom(const unsigned int times) {
	auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->insert(RAN_NUMS.at(i));
    }
    
	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
		t.start();
		tree->deleteMin();
		t.stop();
		comparisons += tree->comparisons;
		tree->insert(RAN_NUMS.at(i));
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
RBTester::RBTreeInsertRandom(const unsigned int times) {
    auto tree = std::make_shared<RBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->insert(RAN_NUMS.at(i));
    }
	
	Timer t;
    t.start();
	unsigned int comparisons = 0;
    for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
        t.start();
		tree->insert(RAN_NUMS.at(i));
		t.stop();
		comparisons += tree->comparisons;

		tree->deleteMin();
    }
    t.stop();
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
	
	std::cout << "\nTesting RBTreeInsertRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeInsertRandom(i);
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
	
	std::cout << "\nTesting RBTreeDeleteMinRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeDeleteMinRandom(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting RBTreeFindSuccBig\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeFindSuccBig(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting RBTreeFindSuccSmall\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeFindSuccSmall(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting RBTreeFindSuccRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        RBTreeFindSuccRandom(i);
        power++;
        i = pow(2,power);
    }
}

void
RBTester::run(const unsigned int highpower) {	

	//TODO: Skal vi bruge random_engine eller random shuffles indbyggede?
    // fra: en.cppreference.com/w/cpp/algorithm/random_shuffle
	unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 10000);
 
	for (int n = 0; n < (REPS * 2) + pow(2, highpower) + 1; ++n) {
		
		RAN_NUMS.push_back(n);
        UPS.push_back(n);
        DOWNS.push_back(n);
	}

    std::random_shuffle(RAN_NUMS.begin(), RAN_NUMS.end()); // Shuffle the data
    std::reverse(DOWNS.begin(), DOWNS.end()); // Reverse the data

	TestRBTree(highpower);
}