#pragma once

class Node {
public:
	int value, index; 
	static int NodeCount;
	virtual Node* getNode(int index) = 0; 
	virtual int getNodeCount() = 0;
};
