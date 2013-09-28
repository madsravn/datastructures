#include "Dijkstra.hpp"

//Dijkstra::Dijkstra() {

//}


Dijkstra::Dijkstra(std::shared_ptr<IQueue> queue) {
    pq = queue;
}

void
Dijkstra::sayName() {
    pq->sayName();
}

void
Dijkstra::run() {
    while(pq->empty() != true) {
        pq->DeleteMin();
    }
}
