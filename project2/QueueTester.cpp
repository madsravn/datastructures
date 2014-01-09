#include "QueueTester.h"
#include "IQueue.hpp"
#include "Timer.hpp"
#include "VEBTree.h"
#include "BHeap.hpp"
#include "FHeap.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

QueueTester::QueueTester(int t)
{
	type = t;
}

std::shared_ptr<IQueue> QueueTester::MakeQueue()
{
	switch (type)
	{
	case 1:
		return std::make_shared<BHeap>();
	case 2:
		return std::make_shared<FHeap>();
	case 3:
		return std::make_shared<VEBTree>();
	default:
		break;
	}
}

/*
 * INSERT TESTS
 */
void QueueTester::QueueInsertBig(const unsigned int times)
{
	auto tree = MakeQueue();    
    for(unsigned i = 0; i <= times; i++) {
        tree->Insert(i+1, i);
    }
	tree->DeleteMin();

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; i++) {
		tree->comparisons = 0;
        t.start();
		tree->Insert(i+1, i);
		t.stop();
		comparisons += tree->comparisons;

		tree->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void QueueTester::QueueInsertSmall(const unsigned int times)
{
	auto tree = MakeQueue();    
    for(unsigned i = times + REPS + 1; i > REPS; i--) {
        tree->Insert(i+1, i);
    }
	tree->DeleteMin();

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

void QueueTester::QueueInsertRandom(const unsigned int times)
{
	auto tree = MakeQueue();    
    for(unsigned i = times + REPS; i >= REPS; --i) {
        tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }
	tree->DeleteMin();

	Timer t;
    t.start();
	unsigned int comparisons = 0;
    for(unsigned i = 0; i < REPS; ++i) {
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

/*
 * DELE TESTS
 */
void QueueTester::QueueDeleteMinBig(const unsigned int times)
{
	auto tree = MakeQueue();  
    for(unsigned i = 0; i < times; i++) {
        tree->Insert(i+1, i);
    }
    tree->DeleteMin();

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

void QueueTester::QueueDeleteMinSmall(const unsigned int times)
{
	auto tree = MakeQueue();  
    for(unsigned i = times + REPS + 1; i > REPS; i--) {
        tree->Insert(i+1, i);
    }
	tree->DeleteMin();

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

void QueueTester::QueueDeleteMinRandom(const unsigned int times)
{
	auto tree = MakeQueue();   
    for(unsigned i = times; i > 0; i--) {
        tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }
	tree->DeleteMin();
    
	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS + times + 1; i > times + 1; i--) {
		tree->comparisons = 0;
		t.start();
		tree->DeleteMin();
		t.stop();
		comparisons += tree->comparisons;
		tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

/*
 * DECREASE KEY TESTS
 */
void QueueTester::QueueDecreaseKeySmall(const unsigned int times)       
{
	auto fheap = MakeQueue(); 
    for(unsigned i = times + REPS + 1; i > REPS; i--) {
        fheap->Insert(i+1,i);
    }
	fheap->DeleteMin();

	Timer t;
	unsigned int comparisons = 0;
    for(unsigned i = REPS; i > 0; i--) {
        
		std::shared_ptr<INode> node = fheap->Insert(i+1,i);

		fheap->comparisons = 0;
		
		t.start();
		fheap->DecreaseKey(node, i + 1);
		t.stop();
		comparisons += fheap->comparisons;

		fheap->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void QueueTester::QueueDecreaseKeyBig(const unsigned int times)
{
	auto fheap = MakeQueue(); 
    for(unsigned i = 0; i < times + 1; i++) {
        fheap->Insert(i+1,i);
    }
	fheap->DeleteMin();

	Timer t;
	unsigned int comparisons = 0;
    for(unsigned i = times; i < REPS + times; i++) {
        
		std::shared_ptr<INode> node = fheap->Insert(i+1,i);
		fheap->DeleteMin();

		fheap->comparisons = 0;
		
		t.start();
		fheap->DecreaseKey(node, i + 1);
		t.stop();
		comparisons += fheap->comparisons;
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void QueueTester::QueueDecreaseKeyRandom(const unsigned int times)
{
	auto tree = MakeQueue();  
    for(unsigned i = times; i > 0; i--) {
        tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
    }
	tree->DeleteMin();

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS + times + 1; i > times + 1; i--) {
		std::shared_ptr<INode> node = tree->Insert(RAN_NUMS.at(i), RAN_NUMS.at(i+1));
		tree->DeleteMin();

		tree->comparisons = 0;
		
		t.start();
		tree->DecreaseKey(node, i + 1);
		t.stop();
		comparisons += tree->comparisons;
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void QueueTester::TestQueue(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing Queue <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	
	i = 4;
    power = 2;
	
	std::cout << "\nTesting InsertBig\n" << std::endl;
	
	while(power <= highpower) {
        QueueInsertBig(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting InsertSmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        QueueInsertSmall(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting InsertRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        QueueInsertRandom(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting DeleteMinBig\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        QueueDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting DeleteMinSmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
        QueueDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting DeleteMinRandom\n" << std::endl;
    i = 4;
    power = 2;
	while(power <= highpower) {
        QueueDeleteMinRandom(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting DecreaseKeyBig\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		QueueDecreaseKeyBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting DecreaseKeySmall\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		QueueDecreaseKeySmall(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting DecreaseKeyRandom\n" << std::endl;
	i = 4;
    power = 2;
	while(power <= highpower) {
		QueueDecreaseKeyRandom(i);
        power++;
        i = pow(2,power);
    }
}

void QueueTester::run(const unsigned int highpower) {	

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

	TestQueue(highpower);
}