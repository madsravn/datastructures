#include "Fully.hpp"

Fully::Fully() {
    latest = 0;
    m = 1024;
    current = 0;
}

Fully::Fully(size_t tm) {
    latest = 0;
    m = tm;
    current = 0;
}

void
Fully::Insert(int x, int time) {
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "insert";
    doThis(x,time,action);
}

void
Fully::Delete(int x, int time) {
    if(time == 0) {
        time = latest+2;
    }
    std::string action = "delete";
    doThis(x,time,action);
}
