#include "Tester.hpp"
#include "Timer.hpp"
#include <cmath>
#include <random>

Tester::Tester() {}



void
Tester::BHeapInsertBig(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = 0; i > times; ++i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
    t.start();
    for(unsigned i = times; i < REPS + times; ++i) {
        t.start();
		bheap->Insert(i+2,i+2);
		t.stop();

		bheap->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void
Tester::BHeapInsertSmall(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times + REPS; i > REPS; --i) {
        bheap->Insert(i+2,i+2);
    }
	
	Timer t;
    t.start();
    for(unsigned i = 0; i < REPS; ++i) {
        t.start();
		bheap->Insert(i+2,i+2);
		t.stop();

		bheap->DeleteMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::BHeapDeleteMinBig(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times; i > 0; --i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;

	for(unsigned i = REPS; i > 0; --i) {
		t.start();
		bheap->DeleteMin();
		t.stop();
		bheap->Insert(i+2, i+2);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::BHeapDeleteMinSmall(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times; i > 0; --i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;

	for(unsigned i = 0; i < REPS; ++i) {
		t.start();
		bheap->DeleteMin();
		t.stop();
		bheap->Insert(i+2, i+2);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void
Tester::BHeapInsertRand(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();

	for(unsigned i = times + 1; i > 0; --i) {
		bheap->Insert(i+2, RAN_NUMS.at(REPS + i));
    }
	bheap->DeleteMin(); // To get a more interesting tree

    Timer t;
    for(unsigned i = REPS; i > 0; --i) {

		int randomNumber = RAN_NUMS.at(i);
		t.start();
		bheap->Insert(i+2,randomNumber);
		t.stop();

		bheap->DeleteMin(); // To preserve size N of heap
    }
    
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void
Tester::FHeapInsertBig(const unsigned int times) {
    auto fheap = std::make_shared<FHeap>();

	for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree

	unsigned int comparisons = 0;
	
    Timer t;
    for(unsigned i = REPS + times; i > times; --i) {
		fheap->comparisons = 0;
		t.start();
        fheap->Insert(i+2,i+2);
		t.stop();
		comparisons += fheap->comparisons;

		fheap->DeleteMin(); // To preserve size N of heap
    }
    
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
Tester::FHeapInsertSmall(const unsigned int times) {
    auto fheap = std::make_shared<FHeap>();

	for(unsigned i = times + times + 1; i > times; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree

	unsigned int comparisons = 0;
    Timer t;    
    for(unsigned i = 0; i < REPS; ++i) {		
		fheap->comparisons = 0;
		t.start();
        fheap->Insert(i+2,i+2);
		t.stop();
		comparisons += fheap->comparisons;
		
		fheap->DeleteMin(); // To preserve size N of heap
    }
    
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
Tester::FHeapInsertRand(const unsigned int times) {
    auto fheap = std::make_shared<FHeap>();

	for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2, RAN_NUMS.at(REPS + i));
    }
	fheap->DeleteMin(); // To get a more interesting tree

	unsigned int comparisons = 0;
    Timer t;
    for(unsigned i = REPS; i > 0; --i) {

		int randomNumber = RAN_NUMS.at(i);
		fheap->comparisons = 0;
		t.start();
		fheap->Insert(i+2,randomNumber);
		t.stop();
		comparisons += fheap->comparisons;

		fheap->DeleteMin(); // To preserve size N of heap
    }
    
	std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::FHeapDeleteMinBig(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();    
    
	for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree

	unsigned int comparisons = 0;
	Timer t;
	for(unsigned i = REPS; i > 0; --i) {
		fheap->comparisons = 0;
		t.start();
		fheap->DeleteMin();
		t.stop();
		comparisons += fheap->comparisons;

		fheap->Insert(i+2, i+2);
    }
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms\t" << fheap->comparisons << " comparisons" << std::endl;
}

void Tester::FHeapDeleteMinSmall(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();    
    for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree	

	unsigned int comparisons = 0;
	Timer t;
	for(unsigned i = 0; i < REPS; ++i) {
		fheap->comparisons = 0;
		t.start();
		fheap->DeleteMin();
		t.stop();
		comparisons += fheap->comparisons;

		fheap->Insert(i+2, i+2);
    }
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::FHeapDecreaseKey(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();  
	std::vector<std::shared_ptr<FNode>> nodes(times + 1);
    for(unsigned i = 0; i < times + 1; i++) {
		std::shared_ptr<INode> inode = fheap->Insert(i+2,i+2);
		std::shared_ptr<FNode> node = std::static_pointer_cast<FNode>(inode);
		nodes.at(i) = node;
    }
	fheap->DeleteMin();

	unsigned int comparisons = 0;
	Timer t;    
	for(unsigned i = REPS; i > 0; --i) {
		fheap->comparisons = 0;
		t.start();
		fheap->DecreaseKey(nodes.at((rand() * times) % nodes.size()), i + 2);
		t.stop();
		comparisons += fheap->comparisons;
    }
	
	std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::BHeapDecreaseKeyBig(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = 0; i < times; ++i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
    t.start();
    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
        
		std::shared_ptr<INode> node = bheap->Insert(i+2,i+2);
		
		t.start();
		bheap->DecreaseKey(node, i + 1);
		t.stop();
		
		bheap->DeleteMin();
		
	}

    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::BHeapDecreaseKeySmall(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times + REPS; i > REPS; --i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
    t.start();
    for(unsigned i = REPS; i > 0; --i) {
        
		std::shared_ptr<INode> node = bheap->Insert(i+2,i+2);
		
		t.start();
		bheap->DecreaseKey(node, i + 1);
		t.stop();
		
		bheap->DeleteMin();
		
	}

    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::TestBHeap(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing BHeap <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	/*
	i = 2;
    power = 1;

	/*std::cout << "\nTesting BHeapInsertBig\n" << std::endl;
	
	while(power <= highpower) {
        BHeapInsertBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting BHeapInsertSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        BHeapInsertSmall(i);
        power++;
        i = pow(2,power);
    }*/
	/*
	std::cout << "\nTesting BHeapInsertRand\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        BHeapInsertRand(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting BHeapDeleteMinBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        BHeapDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting BHeapDeleteMinSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        BHeapDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }
	*/
	std::cout << "\nTesting BHeapDecreaseKeyBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		BHeapDecreaseKeyBig(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting BHeapDecreaseKeySmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		BHeapDecreaseKeySmall(i);
        power++;
        i = pow(2,power);
    }
}

void Tester::TestFHeap(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing FHeap <<< ***\n" << std::endl;
	unsigned int i = 2;
    int power = 1;
	
	/*std::cout << "\nTesting FHeapInsertBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		FHeapInsertBig(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting FHeapInsertSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        FHeapInsertSmall(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FHeapInsertRand\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		FHeapInsertRand(i);
        power++;
        i = pow(2,power);
    }*/

	std::cout << "\nTesting FHeapDeleteMinBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        FHeapDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FHeapDeleteMinSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        FHeapDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting FHeapDecreaseKey\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		FHeapDecreaseKey(i);
        power++;
        i = pow(2,power);
    }
}

void
Tester::run(const unsigned int highpower) {	

	unsigned int seed = 12345;
    std::default_random_engine dre(seed);
    std::uniform_int_distribution<> dis(1, 1000000);
 
	for (int n = 0; n < (REPS * 2) + pow(2, highpower); ++n) {
		
		RAN_NUMS.push_back(dis(dre));
	}

	//TestFHeap(highpower);
	TestBHeap(highpower);
}