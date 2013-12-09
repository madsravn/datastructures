#ifndef PARTIAL_HPP_
#define PARTIAL_HPP_

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <map>

struct ActionTimeElement {
    std::string action;
    int time;
    int item;
};

class Partial {
    public:
        Partial();
        void Insert(int x, int time=0);
        void Delete(int x, int time=0);
        void Test();
        void printInfo();

    private:
        int latest;
        std::vector<ActionTimeElement> repository;
        std::map<int,int> bt;

        int Undo(ActionTimeElement ate);
        int Redo(ActionTimeElement ate);
        void insertElement(int x);
        int deleteElement(int x);
        void doThis(int x, int time, std::string action);
        void applyAction(ActionTimeElement ate, int t);

};




#endif
