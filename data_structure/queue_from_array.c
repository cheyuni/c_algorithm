#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
int front, rear;
int queue[QUEUE_SIZE];

void init_queue(){
    front = rear = 0;
}

void clear_queue(){
    front = rear;
}

int put(int k){
    if((rear + 1) % QUEUE_SIZE == front){
	printf("Queue overflow\n");
	return -1;
    }
    queue[rear] = k;
    rear = ++rear % QUEUE_SIZE;
    return 1;
}

int get(){
    int i;
    if(rear == front){
	printf("Quere underflow\n");
	return -1;
    }
    i = queue[front];
    front = ++front % QUEUE_SIZE;
    return i;
}

void print_queue(){
    int i = 0;
    for(i = front; i != rear;i = (++i % QUEUE_SIZE)){
	printf("key value is %d\n",queue[i]);
    }
}

int main(int argc, char *argv[])
{
    init_queue();
    put(1);
    put(30);
    put(5);
    put(15);
    put(30);
    put(5);
    put(15);
    put(30);
    put(5);
    print_queue();
    return 0;
}
