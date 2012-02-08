#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _node{
    struct _node * next;
    struct _node * prev;
    int key;
}node;

node * head, * tail;

void init(){
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head -> next = tail;
    head -> prev = head;
    tail -> next = tail;
    tail -> prev = head;
    head -> key = 0;
    tail -> key = 0;    
}
node * find_node(int key){
    node * finder;
    while(finder -> key != key && finder != tail){
	finder = finder -> next;
    }
    return finder;
}


node * insert_after(int key, node * target){
    node * intercepter = (node*)malloc(sizeof(node));
    intercepter -> key = key;
    intercepter -> next =  target -> next;
    target -> next -> prev = intercepter;
    target -> next = intercepter;
    intercepter -> prev = target;
    return intercepter;
}
node * ordered_insert(int key){
    node * intercepter = (node*)malloc(sizeof(node));
    node * scout = head -> next;
    while(scout -> key <= key && scout != tail){
	scout = scout -> next;
    }
    intercepter -> key = key;
    scout -> prev -> next = intercepter;
    intercepter -> prev = scout -> prev;
    intercepter -> next = scout;
    scout -> prev = intercepter;
    return intercepter;
}

void delete_all(){
    node * killer;
    node * scout;
    killer = head;
    scout = head -> next;
    while(scout != tail){
	killer = scout;
	scout -> next -> prev = scout -> prev;
	scout -> prev -> next = scout -> next;
	free(killer);
	scout = scout -> next;
    }
}

void print_list(){
    node * printer;
    printer = head->next;
    while(printer != tail){
	printf("%d\n", printer -> key);
	printer = printer -> next;
    }
}

int main (void){
    init();
    ordered_insert(80);            
    ordered_insert(3);
    ordered_insert(50);
    insert_after(1000, find_node(50));
    insert_after(1000, find_node(1000));
    insert_after(10000, find_node(1000));        
    ordered_insert(2);
    print_list();
    return 0;
}
