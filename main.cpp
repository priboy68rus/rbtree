#include <iostream>
#include "stdlib.h"
#include "stdio.h"

#include "rbtree.h"

using namespace std;

int main() {
	RBTree<int> * t = new RBTree<int>();
	t->insert(0);
	t->insert(1);
	// t->insert(2);
	printf("  %d  \n", t->root->left->key);
	delete t;
	return 0;
}
