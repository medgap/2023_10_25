#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initStack(){
    Node* S = (Node*)malloc(sizeof(Node));
    S->data = 0;
    S->next = NULL;
    return S;
}

void push(Node* S,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}

int isEmpty(Node* S){
    if(S->data == 0 || S->next == NULL) 
        return 1;
    return 0;
}

int pop(Node* S){
    
    if(isEmpty(S)){
        return 0;
    }
    else{
        Node* node = S->next;
        int res = node->data;
        S->next = node->next;
        free(node);
        S->data--;
        return res;
    }
}

void PrintStack(Node* S){
    Node* node = S->next;
    while(node){
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Node* node = initStack();
    push(node,1);
    push(node,2);
    push(node,3);
    push(node,4);
    PrintStack(node);
    printf("pop = %d\n", pop(node));
    PrintStack(node);
    return 0;
}