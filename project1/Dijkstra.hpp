#ifndef DIJKSTRA_HPP_
#define DIJKSTRA_HPP_
#include "IQueue.hpp"
#include <memory>
class Dijkstra {

    public:
        //Dijkstra();
        Dijkstra(std::shared_ptr<IQueue> queue);


    private:
        std::shared_ptr<IQueue> pq;


};
#endif
