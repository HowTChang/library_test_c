#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Node {
	int num;
	char* name;
	struct Node* next;
	struct Node* prev;
}node;



node* createNode(const char* name);

void freeNode(node* n);

void freeList(node* head);

void setConnect(node* m, node* n);

void removeNode(node* n);

void printList(node* head);

void swap(node* m, node* n);

void swapNode(node* m, node* n);

node* findHead(node* n);

node* findTail(node* n);
#endif