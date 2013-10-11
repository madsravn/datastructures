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
    unsigned int comparisons = 0;
    for(unsigned i = times; i < REPS + times; ++i) {
		bheap->comparisons = 0;
        t.start();
		bheap->Insert(i+2,i+2);
		t.stop();
		comparisons += bheap->comparisons;

		bheap->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void
Tester::BHeapInsertSmall(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times + REPS; i > REPS; --i) {
        bheap->Insert(i+2,i+2);
    }
	
	Timer t;
    t.start();
	unsigned int comparisons = 0;
    for(unsigned i = 0; i < REPS; ++i) {
		bheap->comparisons = 0;
        t.start();
		bheap->Insert(i+2,i+2);
		t.stop();
		comparisons += bheap->comparisons;

		bheap->DeleteMin();
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::BHeapDeleteMinBig(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times; i > 0; --i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = REPS; i > 0; --i) {
		bheap->comparisons = 0;
		t.start();
		bheap->DeleteMin();
		t.stop();
		comparisons += bheap->comparisons;

		bheap->Insert(i+2, i+2);
    }

   std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::BHeapDeleteMinSmall(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times; i > 0; --i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
	for(unsigned i = 0; i < REPS; ++i) {
		bheap->comparisons = 0;
		t.start();
		bheap->DeleteMin();
		t.stop();
		comparisons += bheap->comparisons;

		bheap->Insert(i+2, i+2);
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
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


// B�r k�re i O(1)
void Tester::FHeapDeleteMinSmall(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();    
    for(unsigned i = REPS + times + 1; i > REPS; --i) {
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
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::FHeapDecreaseKeyBig(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();    
    for(unsigned i = 0; i < times; ++i) {
        fheap->Insert(i+2,i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
        
		std::shared_ptr<INode> node = fheap->Insert(i+2,i+2);
		fheap->comparisons = 0;
		
		t.start();
		fheap->DecreaseKey(node, i + 1);
		t.stop();
		comparisons += fheap->comparisons;
		fheap->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}  

void Tester::FHeapDecreaseKeySmall(const unsigned int times) {
	auto fheap = std::make_shared<BHeap>();    
    for(unsigned i = times + REPS; i > REPS; --i) {
        fheap->Insert(i+2,i+2);
    }

	Timer t;
	std::shared_ptr<INode> node;
	unsigned int comparisons = 0;

    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
		node = fheap->Insert(i+2, i+2);

		fheap->comparisons = 0;
      
		t.start();
		fheap->DecreaseKey(node, i + 1);
		t.stop();

		comparisons += fheap->comparisons;
		fheap->DeleteMin();
		
	}

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::BHeapDecreaseKeyBig(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = 0; i < times; ++i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
	unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
        
		std::shared_ptr<INode> node = bheap->Insert(i+2,i+2);
		bheap->comparisons = 0;
		
		t.start();
		bheap->DecreaseKey(node, i + 1);
		t.stop();
		comparisons += bheap->comparisons;
		bheap->DeleteMin();
    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}  

void Tester::BHeapDecreaseKeySmall(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = times + REPS; i > REPS; --i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
	std::shared_ptr<INode> node;
	unsigned int comparisons = 0;

    for(unsigned i = REPS; i > 0; --i) {
		node = bheap->Insert(i+2, i+2);

		bheap->comparisons = 0;
      
		t.start();
		bheap->DecreaseKey(node, i + 1);
		t.stop();

		comparisons += bheap->comparisons;
		bheap->DeleteMin();
		
	}

    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << comparisons << " comparisons" << std::endl;
}

void Tester::TestBHeap(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing BHeap <<< ***\n" << std::endl;
	unsigned int i;
	int power;

	
	i = 2;
    power = 1;

	std::cout << "\nTesting BHeapInsertBig\n" << std::endl;
	
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
	
	std::cout << "\nTesting FHeapInsertBig\n" << std::endl;
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

	/*std::cout << "\nTesting FHeapDeleteMinBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        FHeapDeleteMinBig(i);
        power++;
        i = pow(2,power);
    }*/

	std::cout << "\nTesting FHeapDeleteMinSmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
        FHeapDeleteMinSmall(i);
        power++;
        i = pow(2,power);
    }
	
	std::cout << "\nTesting FHeapDecreaseKeyBig\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		FHeapDecreaseKeyBig(i);
        power++;
        i = pow(2,power);
    }

	std::cout << "\nTesting FHeapDecreaseKeySmall\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		FHeapDecreaseKeySmall(i);
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
