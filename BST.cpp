#include "BST.h"
#include <iostream>

/*BST::~BST() {
	std::cout << "In BST Destructor" << std::endl;
	// TODO: Implement destructor
}*/

// NODE FUNCTIONS

BST::Node::Node(const int& the_data, Node* left_val = NULL, Node* right_val = NULL) {
	data = the_data;
	left = left_val;
	right = right_val;
	parent = NULL;
}

int BST::Node::getData() const {
	//std::cout << "In getData" << std::endl;
	return(data);
}

BST::Node* BST::Node::getLeftChild() const {
	//std::cout << "In getLeftChild" << std::endl;
	return(left);
}

BST::Node* BST::Node::getRightChild() const {
	//std::cout << "In getRightChild" << std::endl;
	return(right);
}

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface* BST::getRootNode() const {
	//std::cout << "In getRootNode" << std::endl;
	return(root);
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int the_data){
	//std::cout << "In add adding " << the_data << std::endl;
	//Node *ptr = new Node(the_data);
	return(addRecursive(this->root, the_data));	
}

bool BST::addRecursive(Node*& local_root, int the_data) {
	if(local_root == NULL) { // space found to insert
		local_root = new Node(the_data);
		//std::cout << the_data << " added" << std::endl;
		num_items++;
		return(true);
	}
	else {
		if(the_data < local_root->data) { // the_data goes to the left
			//std::cout << "Recursing through left subtree" << std::endl;
			return(addRecursive(local_root->left, the_data));
		}
		else if(the_data > local_root->data) { // the_data goes to the right
			//std::cout << "Recursing through right subtree" << std::endl;
			return(addRecursive(local_root->right, the_data));
		}
		else { // the data is already in the tree
			//std::cout << the_data << " is already in tree" << std::endl;
			return(false);
		}
	}
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int the_data) {
	//std::cout << "In remove removing " << the_data << std::endl;
	return(removeRecursive(the_data, root));
}

bool BST::removeRecursive(int the_data, Node*& local_root) {
	if(local_root == NULL) { // the_data is not in the tree
		//std::cout << the_data << " is not in tree" << std::endl;
		return(false);
	}
	else {
		if(the_data < local_root->data) { // the_data goes to the left
			return(removeRecursive(the_data, local_root->left));
		}
		else if(the_data > local_root->data) { // the_data goes to the right
			return(removeRecursive(the_data, local_root->right));
		}
		else { // the_data found at local_root
			Node *old_root = local_root;
			if(local_root->left == NULL) {
				//std::cout << the_data << " removed" << std::endl;
				local_root = local_root->right;
				delete old_root;
				num_items--;
				return(true);
			}
			else if(local_root->right == NULL) {
				//std::cout << the_data << " removed" << std::endl;
				local_root = local_root->left;
				delete old_root;
				num_items--;
				return(true);
			}
			else { // find the highest value in the left subtree
				replace(old_root, local_root->left);
				return(true);
			}
		}
	}
}

void BST::replace(Node*& old_root, Node*& local_root) {
	if(local_root->right != NULL) {
		replace(old_root, local_root->right);
	}
	else { //highest value found
		old_root->data = local_root->data; // swap values
		removeRecursive(local_root->data, old_root->left); //remove rightmost value from left subtree
	}
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear() {
	//std::cout << "In clear" << std::endl;
	clearRecursive(root);
	root = NULL;
}

void BST::clearRecursive(Node* local_root) {
	if(local_root != NULL) {
		clearRecursive(local_root->left);
		clearRecursive(local_root->right);
		delete local_root;
	}
}