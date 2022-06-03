#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	this->root = nullptr;
}

void BinaryTree::setRoot(Node* root) {
	this->root = root;
}

void inordine(Node* node) {
	if (dynamic_cast<LeafNode*>(node) != nullptr) {
		cout << node->value << " ";
	}
	else if (dynamic_cast<BinaryNode*>(node) != nullptr) {
		auto x = dynamic_cast<BinaryNode*>(node);
		inordine(x->left);
		cout << x->value << " ";
		inordine(x->right);
	}
}

void BinaryTree::walk() {
	inordine(this->root);
}
