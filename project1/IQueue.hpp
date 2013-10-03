#ifndef IQUEUE_HPP_
#define IQUEUE_HPP_
#include "BNode.hpp"
#include "FNode.hpp"
class IQueue {
    public:
        virtual void MakeHeap() = 0;
        virtual int FindMin() = 0;
        virtual std::shared_ptr<INode> Insert(int k, int priority) = 0;
        virtual int DeleteMin() = 0;
        virtual void DecreaseKey(int k, int i) = 0;
        virtual void sayName() = 0;
        virtual bool empty() = 0;
    protected:
        IQueue() {}

};


#endif
