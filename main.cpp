#include <iostream>
#include "stdlib.h"
#include "stdio.h"

#include "rbtree.h"

using namespace std;

int main() {
	RBTree<int> * t = new RBTree<int>();
	// int a[] = {1, 2, 3, 0, 5, 4};
	// for (int i = 0; i < 6; i++) {
	// 	t->insert(a[i]);
	// }

	// RBIterator<int> it = t->begin();
	// for (it = t->begin(); it != t->end(); ++it) {
	// 	cout << *it << endl;
	// }
	// cout << *it << endl;

	

	delete t;
	return 0;
}
