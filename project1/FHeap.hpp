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
        virtual void DecreaseKey(int k, int i, std::shared_ptr<BNode> bnode,
                std::shared_ptr<FNode> fnode);
        virtual void sayName();
        void Meld(std::shared_ptr<FHeap>);
		std::vector<std::vector<std::shared_ptr<FNode>>> FHeap::bucketSort(std::shared_ptr<FNode> root);
		std::string nodeInfo(std::shared_ptr<FNode> n, int rank);
		std::string toString(std::string label);
    //private:
		std::shared_ptr<FNode> minRoot;

};

#endif
