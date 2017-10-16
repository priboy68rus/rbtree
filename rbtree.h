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
		RBTree() { };
		~RBTree();
		void insert(Key key);
		void remove(Key key);

};



#endif /* _RBTREE */