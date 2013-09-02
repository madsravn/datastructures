#ifndef FHEAP_HPP_
#define FHEAP_HPP_

#include "FTree.hpp"
#include <vector>

class FHeap {
    public:
        FHeap();
    private:
        std::vector<FTree> forest;
};

#endif
