#ifndef PARTIAL_HPP_
#define PARTIAL_HPP_

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <map>
#include "IRetro.hpp"

struct ActionTimeElement {
    std::string action;
    int time;
    int item;
};

class Partial : public IRetro {
    public:
        Partial();
        virtual void Insert(int x, int time=0);
        virtual void Delete(int x, int time=0);
        void Test();
        void printInfo();
        int size() { return sizem; }
        std::vector<ActionTimeElement> repository;
        void doThis(int x, int time, std::string action);
        void applyAction(ActionTimeElement ate, int t);
        int late() { return latest; }
        int Query(int x, int time=0);
        int FindElement(int x);
        std::map<int,int> GetTree(int time);


    private:
        int latest;
        std::map<int,int> bt;
        //BinaryTree btt;
        int Undo(ActionTimeElement ate);
        int Redo(ActionTimeElement ate);
        void insertElement(int x);
        int deleteElement(int x);
        int sizem; //m is described as the amount of updates performed

};




#endif
