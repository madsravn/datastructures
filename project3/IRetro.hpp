#ifndef IRETRO_HPP_
#define IRETRO_HPP_

class IRetro {
    public:
        virtual void Insert(int x, int time=0) = 0;
        virtual void Delete(int x, int time=0) = 0;

        // Maybe include the queries as well?
    protected:
        IRetro() {}

};

#endif
