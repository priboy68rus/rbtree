#ifndef _RBTREE
#define _RBTREE

template <typename Key> class RBTree {

	private:
		class RBNode {
		private:
			Key key;
			Color color;
			RBNode * left, * right, * parent;
		public:
			enum Color {RED = 0, BLACK = 1};
		};

};

#endif