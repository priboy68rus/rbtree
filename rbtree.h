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
		// void rotateLeft(RBNode * n);
		void rotateRight(RBNode * n);


	public:
		RBTree() {};
		~RBTree();
		void insert(Key key);
		void remove(Key key);
		void rotateLeft(RBNode * n);


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
	this->root = new RBNode(key);
}

template <typename Key> void RBTree<Key>::rotateLeft(RBTree<Key>::RBNode * n) {
	RBNode * pivot = n->right;

	pivot->parent = n->parent;

	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}

template <typename Key> void RBTree<Key>::rotateRight(RBTree<Key>::RBNode * n) {
	RBNode * pivot = n->left;

	pivot->parent = n->parent;

	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}

#endif /* _RBTREE */