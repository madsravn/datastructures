#ifndef BHEAP_HPP_
#define BEAHP_HPP

#include <iostream>
#include "BNode.hpp"
#include "IQueue.hpp"
#include <bitset>

class BHeap : public IQueue {
    public:
        BHeap();
        virtual void MakeHeap();
        virtual int FindMin();
        virtual void Insert(int k, int priority);
        virtual void DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(int k, int i);
        virtual void sayName();
        std::string graph();
        std::shared_ptr<BNode> Find(int place);
        void BubbleDown(std::shared_ptr<BNode> node);
        void BubbleUp(std::shared_ptr<BNode> node);
        void Switch(std::shared_ptr<BNode> n1, std::shared_ptr<BNode> n2);

    private:
        std::shared_ptr<BNode> root;
        unsigned int size;
};

#endif

