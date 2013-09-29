#ifndef DIJKSTRA_HPP_
#define DIJKSTRA_HPP_
#include "IQueue.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
class Dijkstra {

    public:
        //Dijkstra();
        Dijkstra(std::shared_ptr<IQueue> queue);
        void sayName();
        void run();
        void load(std::string tfile);


    private:
        std::shared_ptr<IQueue> pq;


};
#endif
