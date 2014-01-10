#include "RetroCopy.hpp"
#include <iostream>


RetroCopy ::RetroCopy () {
	trees = std::vector<std::shared_ptr<IRetro>>();
	currentTime = 0;
}

RetroCopy ::~RetroCopy () {
}

void RetroCopy::add(std::shared_ptr<IRetro> tree) {
	trees.push_back(tree);
	currentTime++;
}

std::shared_ptr<IRetro> RetroCopy::get(int time) {
	if (time < 0 || time > trees.size) 
		std::cout << "Exception occurred: time out of range" << std::endl;

	return trees.at(time);
}

void RetroCopy::clear() {
	trees.clear();
	currentTime = 0;
}