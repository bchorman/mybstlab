#pragma once

#include "BSTInterface.h"
#include "NodeInterface.h"

using namespace std;

class BST: public BSTInterface {
protected:
	struct Node : public NodeInterface {
		// Data Fields
		int data;
		Node *left;
		Node *right;
		Node *parent;
		// Struct Functions
		Node(const int& the_data, Node* left_val, Node* right_val);
		virtual ~Node() {}
		int getData() const;
		Node* getLeftChild() const;
		Node* getRightChild() const;
	};
	Node *root;
	int num_items;
public:
	BST() : root(NULL), num_items(0) {}
	virtual ~BST() {clear();}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface* getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int the_data);

	bool addRecursive(Node*& local_root, int the_data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int the_data);

	bool removeRecursive(int the_data, Node*& local_root);
	
	void replace(Node*& old_root, Node*& local_root);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void clearRecursive(Node* local_root);
};