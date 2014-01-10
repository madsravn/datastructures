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
	auto tester = QueueTester(3);
	//tester.run(10);
	
	std::cout << "----- BHeap -----" << std::endl;
	tester = QueueTester(1);
	//tester.run(10);
	
	std::cout << "----- FHeap -----" << std::endl;
	tester = QueueTester(2);
	//tester.run(10);
	
	std::cout << "Search Tree Testing" << std::endl;
	std::cout << "----- vEB -----" << std::endl;
	VEBTester().run(10);
	
	std::cout << "----- RB -----" << std::endl;
	RBTester().run(10);
	
	system("pause");
}