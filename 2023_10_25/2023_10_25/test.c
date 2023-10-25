#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node;

//单循环链表
//
//Node* initList() {
//	Node* L = (Node*)malloc(sizeof(Node));
//	L->next = L;
//	L->data = 0;
//	return L;
//}
//
//void headInsert(Node* L,int data) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->data = data;
//	node->next = L->next;
//	L->next = node;
//	L->data++;
//}
//
//void tailInsert(Node* L, int data) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	Node* n = L;
//	node->data = data;
//	while (n->next != L) {
//		n = n->next;
//	}
//	node->next = L;
//	n->next = node;
//	L->data++;
//}
//
//int DelList(Node* L, int data) {
//	Node* prenode = L;
//	Node* node = L->next;
//	while (node != L) {
//		if (node->data == data) {
//			prenode->next = node->next;
//			free(node);
//			L->data--;
//			return TRUE;
//		}
//		prenode = node;
//		node = node->next;
//	}
//	return FALSE;
//}
//
//void PrintList(Node* L) {
//	Node* n = L->next;
//	while (n != L) {
//		printf("%d->", n->data);
//		n = n->next;
//	}
//	printf("NULL\n");
//}
//
//int main() {
//
//	Node* n = initList();
//	headInsert(n, 1);
//	headInsert(n, 2);
//	headInsert(n, 3);
//	headInsert(n, 4);
//	headInsert(n, 5);
//	tailInsert(n, 6);
//	tailInsert(n, 7);
//	tailInsert(n, 8);
//	tailInsert(n, 9);
//	tailInsert(n, 10);
//
//	DelList(n, 5);
//	DelList(n, 10);
//
//	PrintList(n);
//	return 0;
//}


//双链表
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* pre;
}Node;

Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	L->pre = NULL;
	L->data = 0;
	return L;
}

void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0) {
		node->next = L->next;
		node->pre = L;
		L->next = node;
		
	}
	else {
		/*node->next = L->next;
		L->next = node;
		node->next->pre = node;
		node->pre = L;*/
		node->pre = L;
		node->next = L->next;
		node->next->pre = node;
		L->next = node;
		
		
	}
	
	L->data++;
}

void tailInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* n = L->next;
	while (n->next) {
		n = n->next;
	}
	node->next = n->next;
	node->pre = n;
	n->next = node;
	

	L->data++;
}

int DelList(Node* L, int data) {
	Node* n = L->next;
	while (n) {
		if (n->data == data) {
			if (n->next != NULL) {
				n->pre->next = n->next;
				n->next->pre = n->pre;
				free(n);
				L->data--;
				return TRUE;
			}
			else {
				n->pre->next = NULL;
				free(n);
				L->data--;
				return TRUE;
			}

			
		}
		n = n->next;

	}
	return FALSE;
}

void PrintList(Node* L) {
	Node* n = L->next;
	while (n) {
		printf("%d->", n->data);
		n = n->next;
	}
	printf("NULL\n");
}

int main() {

	Node* node = initList();
	headInsert(node, 1);
	headInsert(node, 2);
	headInsert(node, 3);
	headInsert(node, 4);
	headInsert(node, 5);
	DelList(node, 3);
	DelList(node, 1);
	tailInsert(node, 6);
	tailInsert(node, 7);
	tailInsert(node, 8);
	tailInsert(node, 9);
	PrintList(node);

	return 0;
}