#pragma once
#include <iostream>
#include "Node.h"
#include "LeafNode.h"
#include "BinaryNode.h"

using namespace std;

class BinaryTree {
public: 
	Node* root;
	BinaryTree();
	void setRoot(Node* root); 
	void walk();
};