#ifndef FHEAP_HPP_
#define FHEAP_HPP_

#include "FTree.hpp"
#include "IQueue.hpp"
#include <vector>

class FHeap : public IQueue {
    public:
        FHeap();
        virtual void MakeHeap();
    private:
        std::vector<FTree> forest;
};

#endif
