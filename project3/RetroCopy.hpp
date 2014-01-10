#ifndef RETROCOPY_HPP_
#define RETROCOPY_HPP_

#include <vector>
#include <memory>
#include "IRetro.hpp"
#include <map>

class RetroCopy {
	public :
		RetroCopy();
		~RetroCopy();
		void add(std::map<int, int> tree);
		int size();
		std::map<int, int> get(int time);
		void clear();

	private :
		std::vector<std::map<int, int>> trees;
		int currentTime;
};

#endif