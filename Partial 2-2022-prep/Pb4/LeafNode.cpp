#include "LeafNode.h"

LeafNode::LeafNode(int value) {
	this->value = value; 
	this->index = ++NodeCount;
}

Node* LeafNode::getNode(int index) {
	if (index == this->index) {
		return this;
	}
	return nullptr;
}

int LeafNode::getNodeCount() {
	return this->index;
}
