#ifndef _RBTREE
#define _RBTREE

#include "stdio.h"
#include <iostream>


template <typename Key> class RBTree {

	public:
		enum Color {RED = 0, BLACK = 1};
		class RBNode {
		public:
			Key key;
			Color color;
			RBNode * left, * right, * parent;
			bool isLeaf;
			RBNode(Key key);
			RBNode();
		};

		RBNode * root;
		void destroyTree(RBNode * root);
		void rotateLeft(RBNode * n);
		void rotateRight(RBNode * n);
		void insertRecursive(RBNode * n);
		void createLeaves(RBNode * n);
		void repairTree(RBNode * n);
		RBNode * getUncle(RBNode * n);



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
	this->isLeaf = true;
}

template <typename Key> RBTree<Key>::RBNode::RBNode(Key key) {
	this->key = key;
	this->color = RED;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
	this->isLeaf = false;
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


template <typename Key> void RBTree<Key>::createLeaves(RBTree<Key>::RBNode * n) {
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
	while (!r->isLeaf) {
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
	n->parent = r->parent;

	delete r;
}

template <typename Key> void RBTree<Key>::repairTree(RBTree<Key>::RBNode * n) {
	RBNode * p, *g, *u;

	// Case 1
	if (n->parent == NULL) {
		n->color = BLACK;
		return;
	}

	p = n->parent;

	// Case 2
	if (p->color == BLACK)
		return;

	// Suggesting that grandparent exists
	g = p->parent;
	u = getUncle(n);
	if (g == NULL)
		return;

	// Case 3
	if (u->color == RED) {
		p->color = BLACK;
		u->color = BLACK;
		g->color = RED;
		repairTree(g);
		return;
	}

	// Case 4
	if (n == g->left->right) {
		rotateLeft(p);
		n = n->left;
	} else if (n == g->right->left) {
		rotateRight(p);
		n = n->right;
	}

	p = n->parent;
	g = p->parent;
	if (n == p->left) {
		rotateRight(g);
	} else {
		rotateLeft(g);
	}
	p->color = BLACK;
	g->color = RED;

}


template <typename Key> typename RBTree<Key>::RBNode * RBTree<Key>::getUncle(RBTree<Key>::RBNode * n) {
	if (n == NULL) return NULL;
	if (n->parent == NULL) return NULL;
	if (n->parent->parent == NULL) return NULL;
	if (n->parent == n->parent->parent->left) {
		return n->parent->parent->right;
	} else {
		return n->parent->parent->left;
	}
}

template <typename Key> void RBTree<Key>::insert(Key key) {
	RBNode * n = new RBNode(key);

	insertRecursive(n);

	createLeaves(n);

	repairTree(n);

	RBNode * r = n;
	while (r->parent != NULL) {
		r = r->parent;
	}
	this->root = r;

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