#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node * next;
    int value;
}node;

node * head, *tail;
int now;

void init_stack(){
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head -> next = tail;
    tail -> next = tail;
    now = 0;
}

int push(int value){
    node * input = (node*)malloc(sizeof(node));
    input -> next = head -> next;
    head -> next = input;
    input -> value = value;
    return input -> value;
}

int pop(){
    node * killer;
    killer = head -> next;
    head -> next = head -> next -> next;
    printf("%d is poped", killer -> value);    
    free(killer);
    return head -> next -> value;
}

void print_list(){
    node * viewer;
    viewer = head -> next;
    while(viewer != tail){
	printf("%d \n", viewer -> value);
	viewer = viewer -> next;
    }
}


int main(int argc, char *argv[])
  {
    init_stack();
    push(10);
    push(20);
    pop();
    print_list();

    return 0;
}

