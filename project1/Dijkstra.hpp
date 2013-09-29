#ifndef DIJKSTRA_HPP_
#define DIJKSTRA_HPP_
#include "IQueue.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

struct vw {
    int v,w;
};
class Dijkstra {

    public:
        //Dijkstra();
        Dijkstra(std::shared_ptr<IQueue> queue);
        void sayName();
        void run();
        void load(std::string tfile);


    private:
        std::shared_ptr<IQueue> pq;
        std::multimap<int, vw> edges;

};
#endif
