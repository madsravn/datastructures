#ifndef BHEAP_HPP_
#define BHEAP_HPP_

#include <iostream>
#include "BNode.hpp"
#include "IQueue.hpp"
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <memory>

class BHeap : public IQueue {
    public:
		int comparisons;

        BHeap();
        virtual void MakeHeap();
        virtual int FindMin();
        virtual std::shared_ptr<INode> Insert(int k, int priority);
        virtual int DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(std::shared_ptr<INode> k, int i);
        virtual void sayName();
        virtual bool empty();
        std::string graph();
        std::shared_ptr<BNode> Find(int place);
        void BubbleDown(std::shared_ptr<BNode> node);
        void BubbleUp(std::shared_ptr<BNode> node);
        void Switch(std::shared_ptr<BNode> n1, std::shared_ptr<BNode> n2);
        void printInformation();
        virtual void DecreaseKeyTo(std::shared_ptr<INode> k, int i);        
    private:
        std::shared_ptr<BNode> root;
        unsigned int size;
        int ups,downs,inserts,lookups,deletions,swaps;
};

#endif

