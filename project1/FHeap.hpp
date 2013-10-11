#ifndef FHEAP_HPP_
#define FHEAP_HPP_

#include "FTree.hpp"
#include "IQueue.hpp"
#include <vector>
#include <iostream>
#include <unordered_map>

class FHeap : public IQueue {
    public:
        FHeap();
        virtual void MakeHeap();
        virtual int FindMin();
        virtual std::shared_ptr<INode> Insert(int k, int priority);
        virtual int DeleteMin();
        //Decrease value of Node k with i.
        virtual void DecreaseKey(std::shared_ptr<INode> keyNode, int i);
        virtual void sayName();
        virtual bool empty();
        std::shared_ptr<FNode> Meld(std::shared_ptr<FHeap>);
		std::vector<std::list<std::shared_ptr<FNode>>> bucketSort(std::shared_ptr<FNode> root);
		std::string nodeInfo(std::shared_ptr<FNode> n, int rank);
		std::string toString(std::string label);
		void cascadingCuts(std::shared_ptr<FNode> child);
		std::unordered_map<int, std::shared_ptr<FNode>> map;
		int comparisons;
    private:
		std::shared_ptr<FNode> minRoot;
};

#endif
