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
    int INF = 1000000;
    std::map<int,int> dist;
    std::map<int, std::shared_ptr<INode>> nodes;
	dist.insert(std::make_pair(1,0));
    std::shared_ptr<INode> n = pq->Insert(1,0);
    nodes.insert(std::make_pair(n->key, n));
    std::shared_ptr<BNode> bnode = std::static_pointer_cast<BNode>(n);
    std::cout << "Prio: " << bnode->prio << std::endl;

    for(auto elem : edges) {
        if(dist.count(elem.second.v) == 0) {
            std::shared_ptr<INode> node = pq->Insert(elem.second.v, INF);
            nodes.insert(std::make_pair(node->key,node));
			dist.insert(std::make_pair(elem.second.v,INF));
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
                pq->DecreaseKey(nodes.at(v),1000-mindist); 
                //pq->DecreaseKey(v, 1000-mindist);
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
			edges.insert(std::make_pair( u, edgeweight));
        }

    } else {
        std::cout << "Could not open file: " << tfile << std::endl;
    }
}
