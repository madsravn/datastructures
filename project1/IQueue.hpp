#ifndef IQUEUE_HPP_
#define IQUEUE_HPP_

class IQueue {
    public:
        virtual void MakeHeap() = 0;
        virtual int FindMin() = 0;
        virtual void Insert(int i) = 0;
        virtual void DeleteMin() = 0;
        virtual void DecreaseKey(int k, int i) = 0;
        virtual void sayName() = 0;
    protected:
        IQueue() {}

};


#endif
