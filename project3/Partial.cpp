#include "Partial.hpp"
#include <cassert>

Partial::Partial() {
    // Nothing yet
    latest=0;
}

int
Partial::Redo(ActionTimeElement ate) {
    if(ate.action == "insert") {
        bt.insert(ate.item, ate.item);
    }
    if(ate.action == "delete") {
        // We know the element exist because it is in our repo
        bt.del(bt.predecessor(ate.item));
    }
    return ate.time;

}

int
Partial::Undo(ActionTimeElement ate) {
    if(ate.action == "insert") {
        bt.del(bt.predecessor(ate.item));
    }
    if(ate.action == "delete") {
        bt.insert(ate.item, ate.item);
    }
    return ate.time;

}

void
Partial::insertElement(int x) {
    bt.insert(x,x);
}

int
Partial::deleteElement(int x) {
    std::shared_ptr<BinaryNode> node = bt.predecessor(x);
    if(node->key == x) {
        bt.del(node);
        return 1;
    }
    return 0;
}

void
Partial::applyAction(ActionTimeElement ate) {
    if(ate.action == "insert") {
        insertElement(ate.item);
        latest = ate.time;
        repository.push_back(ate);

    } else {
        if(deleteElement(ate.item)) {
            latest = ate.time;
            repository.push_back(ate);

        }
    }
}

void 
Partial::doThis(int x, int time, std::string action) {
     
    if(time > latest) {
        ActionTimeElement ate = {action,time, x};
        applyAction(ate);
        
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
        applyAction(ate);
    
        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }

    }
}


//TODO: Refactor Insert og Delete functionality into one. Less overhead
void
Partial::Insert(int x, int time) {
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "insert";
    doThis(x,time,action);

    /*std::cout << "Insert " << x << " at " << time << std::endl; 
    if(time > latest) {
        ActionTimeElement ate = {"insert",time, x};
        repository.push_back(ate);
        bt.insert(x,x);
        latest = time;
    } else {
        std::vector<ActionTimeElement> temp;
        for(int i = repository.size()-1; i >= 0; --i) {
            if(repository.at(i).time > time) {
                temp.push_back(repository.at(i));
                Undo(repository.at(i));
                repository.pop_back();
            }

        }
        ActionTimeElement ate = {"insert", time, x};
        bt.insert(x,x);
        repository.push_back(ate);
        //latest = time;
    
        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }

    }
    */
}

void
Partial::Delete(int x, int time) {
    
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "delete";
    doThis(x,time,action);
    /*
    if(time > latest) {
        ActionTimeElement ate = {"delete",time, x};
        std::shared_ptr<BinaryNode> node = bt.predecessor(x);
        if(node->key == x) {
            repository.push_back(ate);
            bt.del(node);
            latest = time;
        } else {
            std::cout << "error" << std::endl;
        }
    } else {
        std::vector<ActionTimeElement> temp;
        for(int i = repository.size()-1; i >= 0; --i) {
            if(repository.at(i).time > time) {
                temp.push_back(repository.at(i));
                Undo(repository.at(i));
                repository.pop_back();
            }

        }
        ActionTimeElement ate = {"delete", time, x};
        std::shared_ptr<BinaryNode> node = bt.predecessor(x);
        if(node->key == x) {
            bt.del(node);
            repository.push_back(ate);
            //latest = time;
        } else {
            std::cout << "error" << std::endl;
        }
        for(int i = temp.size()-1; i >= 0; --i) {
            repository.push_back(temp.at(i));
            Redo(temp.at(i));
        }

    }*/


}

void
Partial::Test() {
    for(int i = 1; i < 10; i++) {
        bt.insert(i,i);
    }
    std::cout << bt.predecessor(7)->key << " found." << std::endl;
}

void
Partial::printInfo() {
    for(int i = 0; i < repository.size(); ++i) {
        std::cout << repository.at(i).time << ": " << repository.at(i).action << " - " << repository.at(i).item << std::endl;
    }
    // Information regarding the actual tree
}
