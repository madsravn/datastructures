﻿#include "VEBTester.h"
#include "VEBTree.h"
#include "Timer.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

VEBTester::VEBTester() {}

void
VEBTester::VEBTreeInsertBig(const unsigned int times) {
    auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(i+1, i);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times; i < REPS + times; i++) {
		tree->comparisons = 0;
        t.start();
		tree->Insert(i+1, i);
		t.stop();
		comparisons += tree->comparisons;

		tree->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
VEBTester::VEBTreeInsert(const unsigned int times, std::vector<int> build_range, std::vector<int> update_range) {
    // Sæt tree til at være en IQueue pointer - og vælg hvad den skal pege på baseret på input
    auto tree = std::make_shared<VEBTree>();
    for(int i : build_range) {
        tree->Insert(i+2,i+2);
    }

    Timer t;
    unsigned int comparisons = 0;
    for(unsigned int i : update_range) {
        tree->comparisons = 0;
        t.start();
        tree->Insert(i+2,i+2);
        t.stop();
        comparisons += tree->comparisons;

        tree->DeleteMin();
    }
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}


void
VEBTester::VEBTreeInsertSmall(const unsigned int times) {
    auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = times + REPS; i > REPS; i--) {
        tree->Insert(i+1, i);
    }
	
	Timer t;
    t.start();
	unsigned int comparisons = 0;
    // This can be made into a vector as well
    for(unsigned i = REPS; i > 0; i--) {
		tree->comparisons = 0;
        t.start();
		tree->Insert(i+1, i);
		t.stop();
		comparisons += tree->comparisons;

		tree->DeleteMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeDeleteMinBig(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(i+1, i);
    }
    
	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS; i++) {
		tree->comparisons = 0;
		t.start();
		tree->DeleteMin();
		t.stop();
		comparisons += tree->comparisons;
		tree->Insert(i+1, i);
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeDeleteMinSmall(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = times + REPS; i > REPS; i--) {
        tree->Insert(i+1, i);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; i--) {
		tree->comparisons = 0;
		t.start();
		tree->DeleteMin();
		t.stop();
		comparisons += tree->comparisons;

		tree->Insert(i+1, i);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeFindSuccSmall(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = times + REPS; i > REPS; i--) {
        tree->Insert(i+1, i);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; i--) {
		tree->comparisons = 0;
		t.start();
		tree->predecessor(i);
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeFindSuccBig(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(i+1, i);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
		t.start();
		tree->predecessor(i);
		t.stop();
		comparisons += tree->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void VEBTester::VEBTreeFindSuccRandom(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
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

void VEBTester::VEBTreeDeleteMinRandom(const unsigned int times) {
	auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }
    
	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
		t.start();
		tree->DeleteMin();
		t.stop();
		comparisons += tree->comparisons;
		tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
VEBTester::VEBTreeInsertRandom(const unsigned int times) {
    auto tree = std::make_shared<VEBTree>();    
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }
	
	Timer t;
    t.start();
	unsigned int comparisons = 0;
    for(unsigned i = times; i < times + REPS ; i++) {
		tree->comparisons = 0;
        t.start();
		tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
		t.stop();
		comparisons += tree->comparisons;

		tree->DeleteMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}



void VEBTester::TestVEBTree(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing VEBTree <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	
	i = 4;
    power = 2;

	std::cout << "\nTesting VEBTreeInsertBig\n" << std::endl;
	
	while(power <= highpower) {
        VEBTreeInsertBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting VEBTreeInsertSmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeInsertSmall(i);
        power++;
        i = pow(2,power);
    }
	
    std::cout << "\nTesting VEBTreeInsertRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeInsertRandom(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting VEBTreeDeleteMinBig\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting VEBTreeDeleteMinSmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting VEBTreeDeleteMinRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeDeleteMinRandom(i);
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

    std::cout << "\nTesting VEBTreeFindSuccRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        VEBTreeFindSuccRandom(i);
        power++;
        i = pow(2,power);
    }

}

void
VEBTester::run(const unsigned int highpower) {	

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

	TestVEBTree(highpower);
}
