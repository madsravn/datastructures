#include "RBNode.h"


RBNode::RBNode(int i)
{
	key = i;
}


RBNode::~RBNode(void)
{
}

bool RBNode::isRed() {
	return color;
}