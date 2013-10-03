#ifndef BHEAP_HPP_
#define BEAHP_HPP

#include <iostream>
#include "BNode.hpp"
#include "IQueue.hpp"
#include <bitset>
#include <cassert>
#include <unordered_map>

class BHeap : public IQueue {
    public:
        BHeap();
        virtual void MakeHeap();
        virtual int FindMin();
        virtual std::shared_ptr<INode> Insert(int k, int priority);
        virtual int DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(int k, int i);
        virtual void sayName();
        virtual bool empty();
        std::string graph();
        std::shared_ptr<BNode> Find(int place);
        void BubbleDown(std::shared_ptr<BNode> node);
        void BubbleUp(std::shared_ptr<BNode> node);
        void Switch(std::shared_ptr<BNode> n1, std::shared_ptr<BNode> n2);
        void Swap();
        void printInformation();

    private:
        std::shared_ptr<BNode> root;
        unsigned int size;
        std::unordered_map<int, std::shared_ptr<BNode>> map;
        int ups,downs,inserts,lookups,deletions,swaps;
};

#endif

