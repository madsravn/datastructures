#include "Tester.hpp"
#include "Timer.hpp"
#include <cmath>
#include <random>
#include <vector>
#include <fstream>

Tester::Tester() {}

void
Tester::DijkstraBHeapLinear(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();
    Dijkstra d(bheap);
    // Generate test file
    std::vector<int> nodes;
    for(int i = 1; i < times; ++i) {
        nodes.push_back(i);
    }
    std::ofstream ofs("testfile.txt");
    if(ofs.good()) {
        for(int i : nodes) {
            ofs << i << " " <<  i+1 << " " << RAN_NUMS.at(i) << std::endl;
        }
        ofs.close();
    }
    d.load("testfile.txt");
    Timer t;
    t.start();
    d.run();
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << std::endl;
}

void
Tester::DijkstraBHeapComplete(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();
    Dijkstra d(bheap);

    std::vector<int> nodes;
    for(int i = 1; i < times; ++i) {
        nodes.push_back(i);
    }
    std::ofstream ofs("testfile.txt");
    if(ofs.good()) {
        for(int i : nodes) {
            for(int j : nodes) {
                if(i != j) {
                    ofs << i << " " << j << " " << RAN_NUMS.at(i) << std::endl;
                }
            }
        }
        ofs.close();
    }
    d.load("testfile.txt");
    Timer t;
    t.start();
    d.run();
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << std::endl;
}

void
Tester::DijkstraFHeapLinear(const unsigned int times) {
    auto fheap = std::make_shared<FHeap>();
    Dijkstra d(fheap);

    std::vector<int> nodes;
    for(int i = 1; i < times; ++i) {
        nodes.push_back(i);
    }
    std::ofstream ofs("testfile.txt");
    if(ofs.good()) {
        for(int i : nodes) {
            ofs << i << " " << i+1 << " " << RAN_NUMS.at(i) << std::endl;
        }
        ofs.close();
    }
    d.load("testfile.txt");
    Timer t;
    std::cout << "Starting timer" << std::endl;
    t.start();
    d.run();
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << std::endl;
}

void
Tester::DijkstraFHeapComplete(const unsigned int times) {
    auto fheap = std::make_shared<FHeap>();
    Dijkstra d(fheap);

    std::vector<int>nodes;
    for(int i = 1; i < times; ++i) {
        nodes.push_back(i);
    }
    std::ofstream ofs("testfile.txt");
    if(ofs.good()) {
        for(int i : nodes) {
            for(int j : nodes) {
                ofs << i << " " << j << " " << 2 << std::endl;
            }
        }
        ofs.close();
    }
    d.load("testfile.txt");
    Timer t;
    t.start();
    d.run();
    t.stop();
    std::cout << "N: \t" << times << "\t" << t.duration().count() <<  " ms\t" << std::endl;
}


void
Tester::BHeapInsertBig(const unsigned int times) {
    auto bheap = std::make_shared<BHeap>();    
    for(unsigned i = 0; i < times; ++i) {
        bheap->Insert(i+2,i+2);
    }

	Timer t;
    unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
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
	for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
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
    for(unsigned i = 0; i < times + 1; ++i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin();

	Timer t;
	unsigned int comparisons = 0;
    for(unsigned i = times + 1; i < REPS + times + 1; ++i) {
        
		std::shared_ptr<INode> node = fheap->Insert(i+2,i+2);
		fheap->DeleteMin();

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
    for(unsigned i = times + REPS + 1; i > REPS + 1; --i) {
        fheap->Insert(i+2,i+2);
    }
	fheap->DeleteMin();

	Timer t;
	std::shared_ptr<INode> node;
	unsigned int comparisons = 0;

    for(unsigned i = REPS; i > 0; --i) {
		node = fheap->Insert(i, i);
		node = fheap->Insert(i+1, RAN_NUMS.at(i));
		fheap->DeleteMin();

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

void
Tester::TestDijkstra(const unsigned int highpower) {
    std::cout << "\n *** >>> Testing Dijkstra <<< ***\n" << std::endl;
    unsigned int i = 2;
    int power = 1;
    /* 
    std::cout << "\nTesting DijkstraBHeapLinear\n" << std::endl;
    i = 2;
    power = 1;
    while(power <= highpower) {
        DijkstraBHeapLinear(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting DijkstraBHeapComplete\n" << std::endl;
    i = 2;
    power = 1;
    while(power <= highpower) {
        DijkstraBHeapComplete(i);
        power++;
        i = pow(2,power);
    }
    */
    std::cout << "\nTesting DijkstraFHeapLinear\n" << std::endl;
    i = 2;
    power = 1;
    while(power <= highpower) {
        DijkstraFHeapLinear(i);
        power++;
        i = pow(2,power);
    }

    std::cout << "\nTesting DijkstraFHeapComplete\n" << std::endl;
    i = 2;
    power = 1;
    while(power <= highpower) {
        DijkstraFHeapComplete(i);
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
	*/
	/*std::cout << "\nTesting FHeapDeleteMinBig\n" << std::endl;
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
    }*/
	
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
    std::uniform_int_distribution<> dis(1, 10000);
 
	for (int n = 0; n < (REPS * 2) + pow(2, highpower); ++n) {
		
		RAN_NUMS.push_back(dis(dre));
	}

	TestFHeap(highpower);
	//TestBHeap(highpower);
    TestDijkstra(highpower);
}
