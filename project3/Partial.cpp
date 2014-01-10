#include "Partial.hpp"
#include <cassert>

Partial::Partial() {
    // Nothing yet
    latest=0;
    sizem = 0;
}

// Redo a given action.
// "insert 5" becomes "insert 5"
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
Partial::FindElement(int x) {
    auto it = bt.lower_bound(x);
    if(it != bt.begin()) {
        --it;
        return it->second;
    }
    //if(it != bt.end()) {
    //    return it->second;
    //}
    return -1;
}


int
Partial::Query(int x, int time) {
    if(time > latest) {
       return FindElement(x); 
    } else {
        std::vector<ActionTimeElement> temp;
        for(int i = repository.size()-1; i >= 0; --i) {
            if(repository.at(i).time > time) {
                temp.push_back(repository.at(i));
                Undo(repository.at(i));
                repository.pop_back();
            } else {
                break;
            }

        }
        return FindElement(x); 

        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }
    }
    return -1;
} 

std::map<int, int>
Partial::GetTree(int time) {
	std::map<int,int> queryt;
    if(time > latest) {
       return bt;
    } else {
        std::vector<ActionTimeElement> temp;
        for(int i = repository.size()-1; i >= 0; --i) {
            if(repository.at(i).time > time) {
                temp.push_back(repository.at(i));
                Undo(repository.at(i));
                repository.pop_back();
            } else {
                break;
            }

        }
		queryt = bt;
        
        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }
        return queryt;

    }
    
}


// Undo or "reverse" a given action. 
// "insert 5" becomes "delete 5"
int
Partial::Undo(ActionTimeElement ate) {
    //std::cout << "Entering undo" << std::endl;
    if(ate.action == "insert") {
        auto it = bt.find(ate.item);
        bt.erase(it);
    }
    if(ate.action == "delete") {
        bt.insert(std::make_pair(ate.item,ate.item));
    }
    return ate.time;

}

// Insert the specified element into the tree structure
void
Partial::insertElement(int x) {
    bt.insert(std::make_pair(x,x));
}

// Delete the specified element from the tree structure
int
Partial::deleteElement(int x) {
    auto it = bt.find(x);
    if(it != bt.end()) {
        bt.erase(x);
        return 1;
    }
    return 0;
}

// t determines whether or not this is the latest action
// So we will not set `latest` if t is 0
void
Partial::applyAction(ActionTimeElement ate, int t) {
    // Actions are "insert" or "delete"
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

// Inserts or deletes an element at a given time.
// If time is before the latest action, the elements
// from the tree will be removed and then inserted again

void 
Partial::doThis(int x, int time, std::string action) {
    //std::cout << "You asked me to " << action << " element " << x << " at time " << time << ". My latest is " << latest << std::endl;
     
    if(time > latest) {
        ActionTimeElement ate = {action,time, x};
        // apply the action as the newest action
        applyAction(ate,1);
        
    } else {
        std::vector<ActionTimeElement> temp;
        for(int i = repository.size()-1; i >= 0; --i) {
            if(repository.at(i).time > time) {
                temp.push_back(repository.at(i));
                Undo(repository.at(i));
                repository.pop_back();
            } else {
                break;
            }

        }
        ActionTimeElement ate = {action,time, x};
        // apply the action as something in the past
        applyAction(ate,0);
    
        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }

    }
    sizem++;
}

// Public access to insert a given element at a given
// time
void
Partial::Insert(int x, int time) {
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "insert";
    doThis(x,time,action);

}

// Public access to delete a given element at a given
// time
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


// So let us get some information about our datastructure
void
Partial::printInfo() {
    for(int i = 0; i < repository.size(); ++i) {
        std::cout << repository.at(i).time << ": " << repository.at(i).action << " - " << repository.at(i).item << std::endl;
    }
    //TODO: Information regarding the actual tree
}
