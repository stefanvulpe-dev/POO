#pragma once
#include "Node.h"

class LeafNode : public Node {
public: 
	LeafNode(int val);
	Node* getNode(int index) override; 
	int getNodeCount() override;
};