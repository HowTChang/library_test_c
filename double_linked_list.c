#define _CRT_SECURE_NO_WARNINGS
#include"double_linked_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int nodeId = 0;
node* head = NULL;
node* tail = NULL;

node* Node(const char* name) {
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
		printf("Oop! something wrong!");
		return NULL;
	}

	size_t length = strlen(name);

	newNode->name = (char*)malloc(length + 1);

	if (newNode->name == NULL) {
		free(newNode);
		printf("Error! memory locate error!");
		return NULL;
	}
	newNode->num = -1;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}



node* createNode(const char* name) {

	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
		printf("Oop! something wrong!");
		return NULL;
	}

	size_t length = strlen(name);

	newNode->name = (char*)malloc(length + 1);

	if (newNode->name == NULL) {
		free(newNode);
		printf("Error! memory locate error!");
		return NULL;
	}
	newNode->num = nodeId++;
	strcpy(newNode->name, name);

	if (head == NULL) {  
	head = newNode;
	tail = newNode;
	newNode->next = NULL;
	newNode->prev = NULL;
	}
	else {
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	return newNode;
}

node* tmpNode() {
	node* tmp = Node("NULL");
	return tmp;
}

void freeNode(node* n) {
	if (n != NULL) {
		printf("sucessfully free Node %s !\n", n->name);
		free(n->name);
		free(n);
	}
	else {
		printf("node isn't eixst!\n");
	}
}

void freeList(node* head) {
	if (head == NULL || head->prev != NULL) {
		printf("there something wrong about the list head!\n");
		return;
	}
	node* current = head;
		node* nextNode = current->next;
		freeNode(current);
		current = nextNode;
	
	printf("clean all!");
	return;
}

void setConnect(node* m, node* n) {
	if (m != NULL && n != NULL) {
		m->next = n;
		n->prev = m;
		printf("sucessfully connect Node %s and Node %s !\n", m->name, n->name);
		n->num = m->num + 1;
	}
	else {
		printf("Error! node isn't exist!\n");
	}
}

void removeNode(node* n) {
	if (n != NULL) {
		if (n->next == NULL) {
			n->prev->next = NULL;
			tail = n->prev;
		}
		else if (n->prev == NULL) {
			n->next->prev = NULL;
			head = n->next;
		}
		else {
			n->prev->next = n->next;
			n->next->prev = n->prev;
		}
		printf("remove Node %s !\n", n->name);
		freeNode(n);
	}
	else {
		printf("Error! node isn't exist!\n");
	}
}

void printList(node* head) {
	if (head == NULL) {
		printf("The list is NULL!\n");
		return;
	}
	node* current = head;
	while (current != NULL) {
		printf("Node num: %d, Node name: %s \n", current->num, current->name);
		if (current->next != NULL) {
			current = current->next;
		}
		else {
			current = NULL;
			printf("list end!\n");
		}
	}
}

void swap(node* m, node* n) {//only assume n > m

	node* temp = Node("temp");

	temp->num = n->num;
	temp->name = n->name;
	temp->next = n->next;
	temp->prev = n->prev;

	n->num = m->num;
	n->name = m->name;
	n->next = m->next;
	m->next->prev = n;
	n->prev = m->prev;
	m->prev->next = n;

	m->num = temp->num;
	m->name = temp->name;
	m->next = temp->next;
	temp->next->prev = m;
	m->prev = temp->prev;
	temp->prev->next = m;

	freeNode(temp);
	return;
}

void swapNode(node* m, node* n) {
	if (m == NULL || n == NULL) {
		printf("There something wrong about node value to swap! \n");
		return;
	}
	node* temp = Node("temp");
	if (n->num > m->num) {
		swap(m, n);
		printf("swap Node %d and Node %d !\n", n->num, m->num);
		return;
	}
	else if (m->num > n->num) {
		swap(n, m);
		printf("swap Node %d and Node %d !\n", n->num, m->num);
		return;
	}
	else {
		printf("swap num error!\n");
	}
	freeNode(temp);
}

node* findHead(node* n) {
	if (n == NULL) {
		printf("Error! node is NULL!\n");
		return NULL;
	}
	else if (n->prev == NULL) {
		return n;
	}
	else {
		while (n->prev != NULL) {
			n = n->prev;
		}
		printf("head Node is %s !\n", n->name);
		return n;
	}
}

node* findTail(node* n) {
	if (n == NULL) {
		printf("Error! node is NULL!\n");
		return NULL;
	}
	else if (n->next == NULL) {
		return n;
	}
	else {
		while (n->next != NULL) {
			n = n->next;
		}
		printf("tail Node is %s !\n", n->name);
		return n;
	}
}

node* search(int position) {
	if (head == NULL) {
		printf("Error head is NULL and search stop!\n");
		return NULL;
	}
	node* current = head;
	while (current != NULL) {
		if (current->num == position) {
			printf("Find it!\n");
			return current;
		}
		current = current->next;
	}
	printf("Error! We don't find it!\n");
	return NULL;
}

void stand_back(node* n) {
	if (n == NULL) {
		return;
	}
	node* current = n;
	while (current != NULL) {
			current->num += 1;
			current = current->next;
	}
	printf("Stand back!!!\n");

}

void move_forward(node* n) {
	if (n == NULL) {
		return;
	}
	node* current = n;
	while (current != NULL) {
		current->num += 1;
		current = current->next;
	}
	printf("Move forward!!!\n");
}




void insertNode(int position, const char* name) {
	if (position < 0 || nodeId+1 < position) {
		printf("Insert Error! Length is invalid!\n");
		return;
	}
	else if (nodeId+1 == position) {
		node* insertNode = createNode(name);
		printf("Insert New Node %s !\n",insertNode->name);
		return;
	}
	else {	
		node* target = search(position);
		node* pre = target->prev;
		node* insertNode = Node(name);
		insertNode->prev = pre;
		insertNode->next = target;
		insertNode->num = position;
		target->prev = insertNode;
		pre->next = insertNode;
		stand_back(target);
		printf("InsertNode!%d and targetNode %d \n",insertNode->num,target->num);
		return;
	}
}


















