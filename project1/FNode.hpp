#ifndef FNODE_HPP_
#define FNODE_HPP_

#include <memory>
#include <list>
class FNode {
    public:
        FNode();
    
    private:
        // TODO: Skal nok laves om til bare to pointers
        // en til højre og en til venstre
        std::list<std::shared_ptr<FNode>> children;

};

#endif
