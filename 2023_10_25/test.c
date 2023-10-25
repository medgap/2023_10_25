#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

//LoopDoubleLinkList
typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

Node* initList(){
    Node* L = (Node*)malloc(sizeof(Node));
    L->next = L;
    L->pre = L;
    L->data = 0;
    return L;
}

void headInsert(Node* L,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next->pre = node;
    node->pre = L;
    L->next = node;
    L->data++;
}

void tailInsert(Node* L,int data){
    Node* node = (Node*)malloc(sizeof(Node));   
    node->data = data;
    Node* n = L;
    while(n->next != L){
        n = n->next;
    }
    node->next = n->next;
    L->pre = node;
    node->pre = n;
    n->next = node;
    L->data++;
}

int DelList(Node* L,int data){
    Node* n = L->next;
    while(n != L){
        if(n->data == data){
            n->pre->next = n->next;
            n->next->pre = n->pre;
            free(n);
            L->data--;
            return TRUE;
        }
        n = n->next;
    }
    return FALSE;
}

void PrintList(Node* L){
    Node* node = L->next;
    while(node != L){
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n");

}

int main(){
    Node* node = initList();
    headInsert(node,1);
    headInsert(node,2);
    headInsert(node,3);
    headInsert(node,4);
    headInsert(node,5);
    tailInsert(node,6);
    tailInsert(node,7);
    tailInsert(node,8);
    tailInsert(node,9);
    tailInsert(node,10);
    DelList(node,5);
    DelList(node,10);
    DelList(node,8);
    PrintList(node);
    return 0;
}