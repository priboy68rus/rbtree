#include <iostream>
#include "stdlib.h"
#include "stdio.h"

#include "rbtree.h"

using namespace std;

int main() {
	RBTree<int> * t = new RBTree<int>();
	delete t;
	return 0;
}
