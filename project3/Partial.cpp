#include "Partial.hpp"
#include <cassert>

Partial::Partial() {
    // Nothing yet
    latest=0;
}

int
Partial::Redo(ActionTimeElement ate) {
    if(ate.action == "insert") {
        bt.insert(std::make_pair(ate.item, ate.item));
    }
    if(ate.action == "delete") {
        // We know the element exist because it is in our repo
        auto it = bt.find(ate.item);
        bt.erase(it);
    }
    return ate.time;

}

int
Partial::Undo(ActionTimeElement ate) {
    if(ate.action == "insert") {
        auto it = bt.find(ate.item);
        bt.erase(it);
    }
    if(ate.action == "delete") {
        bt.insert(std::make_pair(ate.item,ate.item));
    }
    return ate.time;

}

void
Partial::insertElement(int x) {
    bt.insert(std::make_pair(x,x));
}

int
Partial::deleteElement(int x) {
    auto it = bt.find(x);
    if(it != bt.end()) {
        bt.erase(x);
        return 1;
    }
    return 0;
}

void
Partial::applyAction(ActionTimeElement ate, int t) {
    if(ate.action == "insert") {
        insertElement(ate.item);
        if(t) {
            latest = ate.time;
        }
        repository.push_back(ate);

    } else {
        if(deleteElement(ate.item)) {
            if(t) {
                latest = ate.time;
            }
            repository.push_back(ate);

        }
    }
}

void 
Partial::doThis(int x, int time, std::string action) {
     
    if(time > latest) {
        ActionTimeElement ate = {action,time, x};
        applyAction(ate,1);
        
    } else {
        std::vector<ActionTimeElement> temp;
        for(int i = repository.size()-1; i >= 0; --i) {
            if(repository.at(i).time > time) {
                temp.push_back(repository.at(i));
                Undo(repository.at(i));
                repository.pop_back();
            }

        }
        ActionTimeElement ate = {action,time, x};
        applyAction(ate,0);
    
        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }

    }
}


void
Partial::Insert(int x, int time) {
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "insert";
    doThis(x,time,action);

}

void
Partial::Delete(int x, int time) {
    
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "delete";
    doThis(x,time,action);


}

void
Partial::Test() {
}

void
Partial::printInfo() {
    for(int i = 0; i < repository.size(); ++i) {
        std::cout << repository.at(i).time << ": " << repository.at(i).action << " - " << repository.at(i).item << std::endl;
    }
    // Information regarding the actual tree
}
