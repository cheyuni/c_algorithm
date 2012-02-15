#include <stdio.h>
#include <stdlib.h>

typedef struct _queue
{
    struct _queue * next;
    struct _queue * prev;
    int value;
}queue;

queue *tail, *head;
int front, rear;

void init_queue(){
    head = (queue*)malloc(sizeof(queue));
    tail = (queue*)malloc(sizeof(queue));
    head -> prev = head;
    head -> next = tail;
    tail -> prev = head;
    tail -> next = tail;
}

int put(int value){
    queue * node;
    if((node = (queue*)malloc(sizeof(queue))) == NULL){
	printf("Out of memory\n");
	return -1;
    }
    node -> value = value;
    tail -> prev -> next = node;       
    node -> prev = tail -> prev;
    node -> next = tail;
    tail -> prev = node;
    return 1;
}

int get(){
    int value;
    queue * node = (queue*)malloc(sizeof(queue));
    if(head -> next == tail){
	printf("There is no node\n");
	return -1;
    }
    value = head -> next -> value;
    node = head -> next;
    head -> next = head -> next -> next;
    head -> next -> prev = head;    
    free(node);
    return value;
}

void print_queue(){
    queue * chaser;
    chaser = head -> next;
    while(chaser != tail){
	printf("%-5d", chaser -> value);
	chaser = chaser -> next;
    }
    printf("\n\n");
}


int main(int argc, char *argv[])
{
    init_queue();
    put(10);
    put(9);
    put(8);
    put(7);
    put(8);
    put(9);
    put(2);
    put(110);
    put(13094);
    put(989899);
    print_queue();
    get();
    get();
    get();
    print_queue();
    return 0;
}

