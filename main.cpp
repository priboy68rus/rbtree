#include <iostream>
#include "stdlib.h"
#include "stdio.h"

#include "rbtree.h"

using namespace std;

int main() {
	RBTree<int> * t = new RBTree<int>();
	t->insert(0);
	delete t;
	return 0;
}
