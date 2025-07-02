
#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	node* first = createNode("Joshua");
	node* second = createNode("Lily");
	node* third = createNode("Casey");

	//swapNode(first, second);
	//setConnect(first, second);
	//findHead(second);

	printList(first);
	freeList(first);

	//freeNode(first);
	return 0;

}



