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
		void rotateLeft(RBNode * n);
		void rotateRight(RBNode * n);
		void insertRecursive(RBNode * n);
		bool isLeaf(RBNode * n);
		void createLeaves(RBNode * n);


	public:
		RBTree() { root = NULL; };
		~RBTree();
		void insert(Key key);
		void remove(Key key);


};

template <typename Key> RBTree<Key>::RBNode::RBNode() {
	this->color = BLACK;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

template <typename Key> RBTree<Key>::RBNode::RBNode(Key key) {
	this->key = key;
	this->color = RED;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

template <typename Key> RBTree<Key>::~RBTree() {
	destroyTree(this->root);
}

template <typename Key> void RBTree<Key>::destroyTree(RBTree<Key>::RBNode * root) {
	if (root == NULL) return;
	if (root->left != NULL) destroyTree(root->left);
	if (root->right != NULL) destroyTree(root->right);
	if (root != NULL) delete root;
}


template <typename Key> bool RBTree<Key>::isLeaf(RBTree<Key>::RBNode * n) {
	if (n == NULL) return false;
	if (n->left != NULL && n->right != NULL) return true;
	return false;
}

template <typename Key> bool RBTree<Key>::createLeaves(RBTree<Key>::RBNode * n) {
	RBNode * a = new RBNode();
	RBNode * b = new RBNode();
	a->parent = n;
	b->parent = n;
	n->left = a;
	n->right = b;
}


template <typename Key> void RBTree<Key>::insertRecursive(RBTree<Key>::RBNode * n) {
	if (root == NULL) {
		root = n;
		n->parent = NULL;
		return;
	}
	RBNode * r = root;
	while (!isLeaf(r)) {
		if (n->key < r->key) {
			r = r->left;
		} else {
			r = r->right;
		}
	}

	if (r->parent->left == r) {
		r->parent->left = n;
	} else {
		r->parent->right = n;
	}

	delete r;
}

template <typename Key> void RBTree<Key>::insert(Key key) {
	RBNode * n = new RBNode(key);

	insertRecursive(n);

	createLeaves(n);

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