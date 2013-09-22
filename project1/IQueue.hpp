#ifndef IQUEUE_HPP_
#define IQUEUE_HPP_
#include "BNode.hpp"
#include "FNode.hpp"
class IQueue {
    public:
        virtual void MakeHeap() = 0;
        virtual int FindMin() = 0;
        virtual void Insert(int k, int priority) = 0;
        virtual void DeleteMin() = 0;
        virtual void DecreaseKey(int k, int i, std::shared_ptr<BNode> bnode,
                std::shared_ptr<FNode> fnode) = 0;
        virtual void sayName() = 0;
    protected:
        IQueue() {}

};


#endif
