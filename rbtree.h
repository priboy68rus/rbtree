#ifndef _RBTREE
#define _RBTREE

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

		Node * root;
		void destroyTree(root);


	public:
		RBTree();
		~RBTree();
		void insert(Key key);
		void remove(Key key);

};

#endif