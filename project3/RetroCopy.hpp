#ifndef RETROCOPY_HPP_
#define RETROCOPY_HPP_

#include <vector>
#include <memory>
#include "IRetro.hpp"

class RetroCopy {
	public :
		RetroCopy();
		~RetroCopy();
		void add(std::shared_ptr<IRetro> tree);
		std::shared_ptr<IRetro> get(int time);
		void clear();

	private :
		std::vector<std::shared_ptr<IRetro>> trees;
		int currentTime;
};

#endif