#include <iostream>
#include "BinaryTree.h"
#include "VEBTree.h"
#include "VEBTester.h"
#include "RBTester.h"
#include "RBTree.h"

int main() {
	VEBTree tree = VEBTree();
	/*
	tree.insert(71);
	tree.insert(211);
	tree.insert(614);
	tree.insert(13465);
	tree.insert(18123);
	tree.insert(18124);
	tree.insert(121242);
	tree.insert(201412);
	tree.insert(211253);
	tree.insert(412445);
	tree.insert(1056456);
	tree.insert(1604215);
	tree.insert(2014124);
	tree.insert(5133186);
	tree.insert(6142156);
	tree.insert(10115266);
	
	
	std::cout << tree.predecessor(135843)->key << std::endl;
	std::cout << tree.predecessor(1135843)->key << std::endl;
	std::cout << tree.predecessor(2135843)->key << std::endl;
	std::cout << tree.predecessor(843)->key << std::endl;
	std::cout << tree.predecessor(35843)->key << std::endl;
	*/

	RBTester tester = RBTester();
	tester.run(16);
	std::cout << "Press any key" << std::endl;
}
