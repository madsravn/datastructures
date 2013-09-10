#ifndef FHEAP_HPP_
#define FHEAP_HPP_

#include "FTree.hpp"
#include "IQueue.hpp"
#include <vector>
#include <iostream>

class FHeap : public IQueue {
    public:
        FHeap();
        virtual void MakeHeap();
        virtual int FindMin();
        virtual void Insert(int i);
        virtual void DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(int k, int i);
        virtual void sayName();
    private:
        std::vector<FTree> forest;
};

#endif
