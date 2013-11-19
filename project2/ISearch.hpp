#ifndef ISEARCH_HPP_
#define ISEARCH_HPP_
#include "INode.hpp"
class ISearch {
    public:
        virtual std::shared_ptr<INode> predecessor(int i) = 0;
    protected:
        ISearch() {}

};


#endif
