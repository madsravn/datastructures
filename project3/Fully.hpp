#ifndef FULLY_HPP_
#define FULLY_HPP_

#include <vector>
#include "Partial.hpp"

class Fully {
    public:
        Fully();
        Fully(size_t tm);
        void Insert(int x, int time=0);
        void Delete(int x, int time=0);
        void Test();
        void printInfo();


    private:
        int latest;
        int m;
        std::vector<Partial> repo;
        int current;
        int Undo(ActionTimeElement ate);
        int Redo(ActionTimeElement ate);
        void insertElement(int x);
        void deleteElement(int x);
        void doThis(int x, int time, std::string action);
        void applyAction(ActionTimeElement ate, int t);
};


#endif
