#ifndef FULLY_HPP_
#define FULLY_HPP_

#include <vector>
#include <cmath>
#include "Partial.hpp"
#include "IRetro.hpp"

class Fully : public IRetro {
    public:
        Fully();
        Fully(size_t tm);
        virtual void Insert(int x, int time=0);
        virtual void Delete(int x, int time=0);
        void Test();
        void printInfo();
        int Query(int x, int time=0);


    private:
        int latest;
        int m;
        int sqrtm;
        std::vector<Partial> repo;
        int current;
        int position;
        int Undo(ActionTimeElement ate);
        int Redo(ActionTimeElement ate);
        void insertElement(int x);
        void deleteElement(int x);
        void doThis(int x, int time, std::string action);
        void applyAction(ActionTimeElement ate);
        void Rebalance();
        int FindPosition(int time);
        int size(int position);

};


#endif
