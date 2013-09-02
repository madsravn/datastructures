#ifndef FNODE_HPP_
#define FNODE_HPP_

#include <memory>
#include <list>
class FNode {
    public:
        FNode();
    
    private:
        std::list<std::unique_ptr<FNode>> children;

};

#endif
