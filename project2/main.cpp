#include <iostream>
#include "BinaryTree.h"
#include "VEBTree.h"
#include "RBTester.h"
#include "RBTree.h"
#include "QueueTester.h"
#include "BHeap.hpp"
#include "FHeap.hpp"
#include "VEBTester.h"

int main() {
	std::cout << "Queue Testing" << std::endl;
	std::cout << "----- vEB -----" << std::endl;
	auto tester = QueueTester(std::make_shared<VEBTree>());
	tester.run(10);

	std::cout << "----- BHeap -----" << std::endl;
	tester = QueueTester(std::make_shared<BHeap>());
	tester.run(10);

	std::cout << "----- FHeap -----" << std::endl;
	tester = QueueTester(std::make_shared<FHeap>());
	tester.run(10);
	
	std::cout << "Search Tree Testing" << std::endl;
	std::cout << "----- vEB -----" << std::endl;
	VEBTester().run(10);

	std::cout << "----- RB -----" << std::endl;
	RBTester().run(10);

	system("pause");
}
