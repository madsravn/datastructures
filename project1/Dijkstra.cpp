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
    std::map<int,int> visited;
    std::map<int,int> minvalue;
    pq->Insert(1,0); // Vi starter fra node 1 med 0 distance
    minvalue.insert({{1,0}});
    while(pq->empty() != true) {
        int u = pq->DeleteMin();
        if(visited.count(u) > 0) {
            continue;
        }
        for(auto pos = edges.lower_bound(u); pos != edges.upper_bound(u); ++pos) {

            vw weights = pos->second;
            int v = weights.v;
            int w = weights.w;
            int mv = 0;
            if(minvalue.count(v) > 0) {
                mv = minvalue.at(v) + w;
            } else {
                mv = minvalue.at(u) + w + 1;
            }
            if(!visited.count(v) && minvalue.at(u) < mv) {
                minvalue.insert({{v,minvalue.at(u)+w}});
                pq->Insert(v,minvalue.at(v));
            }
        }
        visited.insert({{u,1}});
    }

    // Print resultater:
    for(auto pos = minvalue.begin(); pos != minvalue.end(); ++pos) {
        std::cout << pos->first << " - " << pos->second << std::endl;
    }
}

void
Dijkstra::load(std::string tfile) {
    std::ifstream file(tfile);
    std::string line;
    int u,v,w;
    if(file.is_open()) {
        while(file >> u >> v >> w) {
            std::cout << u << " - " << v << " - " << w << std::endl;
            vw edgeweight = {v,w};
            edges.insert({ { u, edgeweight} });
        }

    } else {
        std::cout << "Could not open file: " << tfile << std::endl;
    }
}
