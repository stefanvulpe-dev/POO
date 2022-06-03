#pragma once
#include "Node.h"

class BinaryNode : public Node {
public: 
	Node* left, * right;
	BinaryNode(int value, Node* left, Node* right);
	Node* getNode(int index) override;
	int getNodeCount() override;
};