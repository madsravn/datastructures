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
        virtual void Insert(int k, int priority);
        virtual void DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(int k, int i);
        virtual void sayName();
        void Meld(std::shared_ptr<FHeap>);
    private:
        std::vector<FTree> forest;
		std::shared_ptr<FNode> minRoot;

};

#endif
