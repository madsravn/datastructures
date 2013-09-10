#ifndef BHEAP_HPP_
#define BEAHP_HPP

#include <iostream>
#include "BNode.hpp"
#include "IQueue.hpp"

class BHeap : public IQueue {
    public:
        BHeap();
        virtual void MakeHeap();
        virtual int FindMin();
        virtual void Insert(int i);
        virtual void DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(int k, int i);
        virtual void sayName();

    private:
        std::shared_ptr<BNode> root;
};

#endif

