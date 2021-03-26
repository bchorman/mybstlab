/*#pragma once

#include <iostream>
#include "NodeInterface.h"

class Node: public NodeInterface {
friend class BST;
public:
	Node(const int& the_data, Node* left_val = NULL, Node* right_val = NULL);

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*
	int getData();

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*
	NodeInterface * getLeftChild();

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*
	NodeInterface * getRightChild();

private:
	int data;
	Node *left;
	Node *right;
};*/