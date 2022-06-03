#include "BinaryNode.h"

BinaryNode::BinaryNode(int value, Node* left, Node* right) {
    this->value = value; 
    this->left = left;
    this->right = right;
    this->index = ++NodeCount;
}

Node* BinaryNode::getNode(int index) {
    if (index == this->index - 2) {
        return this->left;
    }
    else if (index == this->index - 1) {
        return this->right; 
    }
    else if (index == this->index) {
        return this;
    }
    return nullptr;
}

int BinaryNode::getNodeCount() {
    return this->index;
}
