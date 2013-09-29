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

void
Dijkstra::load(std::string tfile) {
    std::ifstream file(tfile);
    std::string line;
    int u,v,w;
    if(file.is_open()) {
        while(file.good()) {
            //std::getline(file,line);
            //line >> u >> v >> w;
            file >> u >> v >> w;
            std::cout << u << " - " << v << " - " << w << std::endl;
        }

    } else {
        std::cout << "Could not open file: " << tfile << std::endl;
    }
}
