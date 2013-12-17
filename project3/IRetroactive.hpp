#ifndef IRETROACTIVE_HPP_
#define IRETROACTIVE_HPP_
class IRetroactive {
    public:
        virtual void insert(int item, int time = 0) = 0;
        virtual void delete(int item, int time = 0) = 0;
        virtual int query(int time) = 0;
    protected:
        IRetroactive() {}

};


#endif
