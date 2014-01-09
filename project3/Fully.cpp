#include "Fully.hpp"

Fully::Fully() {
    latest = 0;
    m = 1024;
    sqrtm = ceil(sqrt(m));
    // Current D_n
    current = 0;
    for(int i = 0; i < sqrtm; ++i) {
        Partial p;
        repo.push_back(p);
    }
}

Fully::Fully(size_t tm) {
    latest = 0;
    m = tm;
    sqrtm = ceil(sqrt(m));
    // Current D_n
    current = 0;
    for(int i = 0; i < sqrtm; ++i) {
        Partial p;
        repo.push_back(p);
    }

}

void
Fully::Insert(int x, int time) {
    if(time == 0) {
        time = latest+2;
        latest +=2;
    }
    std::string action = "insert";
    doThis(x,time,action);
    
}

void
Fully::Delete(int x, int time) {
    if(time == 0) {
        time = latest+2;
        latest+=2;
    }
    std::string action = "delete";
    doThis(x,time,action);
}


void 
Fully::doThis(int x, int time, std::string action) {
     
    ActionTimeElement ate = {action,time, x};
    applyAction(ate);
        
}



// Find the Partial container for a given time. 
int
Fully::FindPosition(int time) {
    for(int i = 0; i < repo.size(); ++i) {
        std::cout << "checking " << i << std::endl;
        // Do we even have any elements?
        if(repo.at(i).size() == 0) {
            return i;
        }

        // We know the container has elements - check the latest time stamp
        if(repo.at(i).late() > time) {
            return i;
        }
        // We know the container has elements and the time is after the latest time stamp
        if(repo.at(i).size() < sqrtm) {
            return i;
        }
    }

    // If the time isn't lower than anything else, return the latest partial
    std::cout << "Returning default value" << std::endl;
    return repo.size()-1;
}

void
Fully::applyAction(ActionTimeElement ate) {


    int i = FindPosition(ate.time);
    repo.at(i).doThis(ate.item, ate.time, ate.action);

    // Update all partials after P_i
    // TODO: UDEN DEN HER VIRKER KODEN FINT - FIND FEJLEN
    /*
    for(int a = i+1; a < repo.size(); ++a) {
        Partial p = repo.at(a);
        repo.at(a) = repo.at(a-1);
        for(auto& ate : p.repository) {
            repo.at(a).doThis(ate.item, ate.time, ate.action);
        }
    }*/

    // Do we need a rebalance?
    // TODO: THE SIZE PER PARTIAL NEEDS TO BE RETHOUGHT!
    if(repo.at(i).repository.size() > 2*sqrtm-1) {
        Rebalance();
    }

}


void
Fully::Rebalance() {
    int newm = 0;
    int rsize = repo.size() - 1;
    std::vector<ActionTimeElement> tempRepo;
    // The last partial container most both contain all the updates and collected size of updates
    std::copy(repo.at(rsize).repository.begin(), repo.at(rsize).repository.end(), tempRepo.begin());
    newm = tempRepo.size();
    m = newm;
    // TODO: Skal det være ceil, floor eller noget andet? 
    sqrtm = ceil(sqrt(m));
    // TODO: assertions
    //assert( sqrtm*sqrtm >= m )
    current = 0;
    position = 0;
    repo.clear();
    
    for(int i = 0; i < sqrtm; ++i) {
        Partial p;
        repo.push_back(p);
    }

    // TODO: Opdater til at passe ideen bag de andre
    for(ActionTimeElement& ate : tempRepo) {
        repo.at(current).doThis(ate.item, ate.time, ate.action);
        ++position;
        if(position > sqrtm) {
            ++current;
            repo.at(current) = repo.at(current-1);
            position = 0;
        }
    }
}

void
Fully::printInfo() {
    std::cout << "m: " << m << std::endl;
    std::cout << "sqrtm: " << sqrtm << std::endl;
    for(int i = 0; i < repo.size(); ++i) {
        std::cout << "<<< === >>>" << std::endl;
        repo.at(i).printInfo();
    }
}
