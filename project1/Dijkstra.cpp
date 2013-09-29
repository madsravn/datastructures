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
    /*std::map<int,int> visited;
    std::map<int,int> minvalue;
    pq->Insert(1,1); // Vi starter fra node 1 med 0 distance
    minvalue.insert({{1,0}});
    while(pq->empty() != true) {
        std::cout << "==============================" << std::endl;
        int u = pq->DeleteMin();
        std::cout << "Vi kigger på node: " << u << std::endl; 
        if(visited.count(u) > 0) {
            std::cout << "Vi har allerede besøgt " << u << std::endl;
            continue;
        }
        for(auto pos = edges.lower_bound(u); pos != edges.upper_bound(u); ++pos) {

            vw weights = pos->second;
            int v = weights.v;
            int w = weights.w;
            std::cout << u << ", " << v << ", " << w << std::endl;
            int mv = 0;
            if(minvalue.count(v) > 0) {
                mv = minvalue.at(v) + w;
            } else {
                mv = minvalue.at(u) + w + 1; // infinity
            }
            std::cout << "mv = " << mv << std::endl;
            if(!visited.count(v) && minvalue.at(u) < mv) {
                std::cout << "value indsat med " << minvalue.at(u)+w << " da minvalue.at(u) var " << minvalue.at(u) << std::endl;
                if(minvalue.count(v) == 0) {
                    minvalue.insert({{v,minvalue.at(u)+w}});
                } else {
                    minvalue.at(v) = minvalue.at(u)+w;
                }
                std::cout << v << "," << minvalue.at(v) <<  " indsat i priokø" << std::endl;
                pq->Insert(v,minvalue.at(v));
            }
        }
        visited.insert({{u,1}});
    }*/
    std::map<int,int> dist;
    dist.insert({{1,0}});
    pq->Insert(1,0);
    for(auto elem : edges) {
        if(dist.count(elem.second.v) == 0) {
            pq->Insert(elem.second.v, 10000);
            dist.insert({{elem.second.v,10000}});
        }
    }
    while(pq->empty() != true) {
        int u = pq->DeleteMin();
        for(auto pos = edges.lower_bound(u); pos != edges.upper_bound(u); ++pos) {
            vw weights = pos->second;
            int v = weights.v;
            int w = weights.w;
            std::cout << u << ", " << v << ", " << w << std::endl;
            int mindist = dist.at(u) + w;
            if(mindist < dist.at(v)) {
                dist.at(v) = mindist;
                pq->DecreaseKey(v, 1000-mindist);
            }

        }
    }

    // Print resultater:
    for(auto pos = dist.begin(); pos != dist.end(); ++pos) {
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
            vw edgeweight = {v,w};
            edges.insert({ { u, edgeweight} });
        }

    } else {
        std::cout << "Could not open file: " << tfile << std::endl;
    }
}
