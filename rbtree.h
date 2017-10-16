#ifndef _RBTREE
#define _RBTREE

#include "stdio.h"
#include <iostream>


template <typename Key> class RBTree {

	private:
		class RBNode {
		public:
			enum Color {RED = 0, BLACK = 1};
			Key key;
			Color color;
			RBNode * left, * right, * parent;
			RBNode(Key key);
		};

		RBNode * root;
		void destroyTree(RBNode * root);


	public:
		RBTree() {};
		~RBTree();
		void insert(Key key);
		void remove(Key key);

};

template <typename Key> RBTree<Key>::RBNode::RBNode(Key key) {
	this->key = key;
	this->color = RED;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

template <typename Key> RBTree<Key>::~RBTree() {
	destroyTree(root);
}

template <typename Key> void RBTree<Key>::destroyTree(RBTree<Key>::RBNode * root) {
	if (root->left != NULL) destroyTree(root->left);
	if (root->right != NULL) destroyTree(root->right);
	if (root != NULL) delete root;
}

template <typename Key> void RBTree<Key>::insert(Key key) {
	
}

#endif /* _RBTREE */