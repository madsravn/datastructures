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
    const unsigned int INF = 10000000;
    std::map<int,int> dist;
    std::map<int, std::shared_ptr<INode>> nodes;
	dist.insert(std::make_pair(1,0));
    std::shared_ptr<INode> n = pq->Insert(1,0);
    nodes.insert(std::make_pair(n->key, n));

    for(auto elem : edges) {
        if(dist.count(elem.second.v) == 0) {
            std::shared_ptr<INode> node = pq->Insert(elem.second.v, INF);
            nodes.insert(std::make_pair(node->key,node));
			dist.insert(std::make_pair(elem.second.v,INF));
        }
    }
	int comps = 0;
    while(pq->empty() != true) {
        int u = pq->DeleteMin();

        //std::cout << "Lortet bliver ved med at køre" << std::endl;
        //for(auto pos = edges.lower_bound(u); pos != edges.upper_bound(u); ++pos) {
        std::pair<std::multimap<int,vw>::iterator, std::multimap<int,vw>::iterator> ret;
        ret = edges.equal_range(u);
        for(auto pos = ret.first; pos != ret.second; ++pos) {
            vw weights = pos->second;
            int v = weights.v;
            int w = weights.w;
            //std::cout << u << ", " << v << ", " << w << std::endl;
            int mindist = dist.at(u) + w;
            if(mindist < dist.at(v)) {
                dist.at(v) = mindist;
                //pq->DecreaseKey(nodes.at(v),140000-mindist); 
                pq->DecreaseKeyTo(nodes.at(v), mindist);
				comps++;
            }
        }
    }
	//std::cout << "Comparison " << comps << std::endl;
    // Print resultater:
    /*for(auto pos = dist.begin(); pos != dist.end(); ++pos) {
        std::cout << pos->first << " - " << pos->second << std::endl;
    }*/
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
