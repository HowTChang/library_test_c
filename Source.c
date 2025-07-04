
#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	node* first = createNode("Joshua");
	node* second = createNode("Lily");
	node* third = createNode("Casey");
	insertNode(1, "HowTang");
	//swapNode(first, second);
	//setConnect(first, second);
	//findHead(second);
	node* head = findHead(second);
	printList(head);
	freeList(head);

	//freeNode(first);
	return 0;

}



