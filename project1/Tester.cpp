#include "Tester.hpp"
#include "Timer.hpp"
#include <cmath>

Tester::Tester() {}

void
Tester::BHeapInsertBig(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();
    Timer t;
    t.start();
    for(unsigned i = times; i > 0; --i) {
        bheap->Insert(i+2,i+2);
    }
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void
Tester::BHeapInsertSmall(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();
    Timer t;
    t.start();
    for(unsigned i = 0; i < times; ++i) {
        bheap->Insert(i+2,i+2);
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

	for(unsigned i = 0; i > REPS; ++i) {
		t.start();
		bheap->DeleteMin();
		t.stop();
		bheap->Insert(i+2, i+2);
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

    Timer t;
    for(unsigned i = REPS; i > 0; --i) {
		t.start();
        fheap->Insert(i+2,i+2);
		t.stop();

		fheap->DeleteMin(); // To preserve size N of heap
    }
    
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void
Tester::FHeapInsertSmall(const unsigned int times) {
    auto fheap = std::make_shared<FHeap>();

	for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree

    Timer t;    
    for(unsigned i = 0; i < REPS; ++i) {
		t.start();
        fheap->Insert(i+2,i+2);
		t.stop();

		fheap->DeleteMin(); // To preserve size N of heap
    }
    
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::FHeapDeleteMinBig(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();    
    
	for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree

	Timer t;

	for(unsigned i = REPS; i > 0; --i) {
		t.start();
		fheap->DeleteMin();
		t.stop();

		fheap->Insert(i+2, i+2);
    }
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::FHeapDeleteMinSmall(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();    
    for(unsigned i = times + 1; i > 0; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin(); // To get a more interesting tree
	
	Timer t;

	for(unsigned i = 0; i > REPS; ++i) {
		t.start();
		fheap->DeleteMin();
		t.stop();
		fheap->Insert(i+2, i+2);
    }
    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::FHeapDecreaseKey(const unsigned int times) {
	auto fheap = std::make_shared<FHeap>();  
	std::vector<std::shared_ptr<FNode>> nodes(times);
    for(unsigned i = 0; i < times; i++) {
		std::shared_ptr<INode> inode = fheap->Insert(i+2,i+2);
		std::shared_ptr<FNode> node = std::static_pointer_cast<FNode>(inode);
		nodes.at(i) = node;
    }

	Timer t;
    
	for(unsigned i = REPS; i > 0; --i) {
		t.start();
		fheap->DecreaseKey(nodes.at((rand() * times) % nodes.size()), i + 2);
		t.stop();

		/*std::shared_ptr<INode> inode = fheap->Insert(i+2,i+2);
		std::shared_ptr<FNode> node = std::static_pointer_cast<FNode>(inode);
		nodes.at(i % nodes.size()) = node;*/

    }
	
	std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}

void Tester::BHeapDecreaseKey(const unsigned int times) {
	auto bheap = std::make_shared<BHeap>();  
	std::vector<std::shared_ptr<INode>> nodes;
    for(unsigned i = 0; i < times; ++i) {
		std::shared_ptr<INode> inode = bheap->Insert(i+2,i+10000);
		nodes.push_back(inode);
    }

	Timer t;

	for(unsigned i = REPS; i > 0; --i) {
		t.start();
        std::shared_ptr<BNode> bnode = std::static_pointer_cast<BNode>(nodes.at(0));
        int index = i % times;
        std::shared_ptr<INode> inode = nodes.at(index);
		bheap->DecreaseKey(inode, 1);
		t.stop();

    }

    std::cout << "N: \t" << times << "\t" << t.duration().count() << " ms" << std::endl;
}  

void Tester::TestBHeap(const unsigned int highpower) {
	std::cout << "\n *** >>> Testing BHeap <<< ***\n" << std::endl;

	std::cout << "\nTesting BHeapInsertBig\n" << std::endl;
	unsigned int i = 2;
    int power = 1;
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

	std::cout << "\nTesting BHeapDecreaseKey\n" << std::endl;
	i = 2;
    power = 1;
	while(power <= highpower) {
		BHeapDecreaseKey(i);
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
	//TestFHeap(highpower);
	TestBHeap(highpower);
}
