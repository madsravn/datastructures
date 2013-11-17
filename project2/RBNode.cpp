#include "RBNode.h"


RBNode::RBNode(int i, std::shared_ptr<RBNode> null)
{
	color = false;
	key = i;
	left = null;
	right = null;
	parent = null;
}


RBNode::~RBNode(void)
{
}

bool RBNode::isRed() {
	return color;
}