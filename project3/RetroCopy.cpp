#include "RetroCopy.hpp"
#include <iostream>


RetroCopy::RetroCopy () {
	trees = std::vector<std::map<int, int>>();
	currentTime = 0;
}

RetroCopy::~RetroCopy () {
}

void RetroCopy::add(std::map<int, int> tree) {
	trees.push_back(tree);
	currentTime++;
}

int RetroCopy::size() {
	return trees.size();
}

std::map<int, int> RetroCopy::get(int time) {
	if (time < 0) 
		std::cout << "Exception occurred: time below range:\t" << time << std::endl;
	if (time > trees.size())
		std::cout << "Exception occurred: time above range:\t" << time << std::endl;

	return trees.at(time);
}

void RetroCopy::clear() {
	trees.clear();
	currentTime = 0;
}
