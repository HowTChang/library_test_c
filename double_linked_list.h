#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Node {
	int num;
	char* name;
	struct Node* next;
	struct Node* prev;
}node;


node* Node(const char* name);

node* createNode(const char* name);

node* tmpNode();

void freeNode(node* n);

void freeList(node* head);

void setConnect(node* m, node* n);

void removeNode(node* n);

void printList(node* head);

void swap(node* m, node* n);

void swapNode(node* m, node* n);

node* findHead(node* n);

node* findTail(node* n);

node* searchNode(int position);

void stand_back(node* n);

void insertNode(int position, node* n);
#endif