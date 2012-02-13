#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
int top;
int stack[STACK_SIZE];
void init_stack(void){
    top = -1;
}

int push(int value){
    if(top > STACK_SIZE){
	printf("\nStack overflow!!\n");
	return 0;
    }
    else{
	stack[++top] = value;
	printf("number %d is inserted\n", stack[top]);
	return 1;
    }
}

int pop(){
    if(top == -1){
	printf("\nStack underfow!!\n");
	return 0;
    }
    else{
	printf("this number is poped : %d", stack[top--]);
	stack[top] = 0;	
	return stack[top];
    }
}

void print_data(){
    int i;
    if (top == -1){
	printf("\nStack is empty\n");
    }
    for(i = 0; i<top + 1; ++i){
	printf("%d :  %d\n", i, stack[i]);
    }
}

int main (void){
    init_stack();
    push(10);
    pop();
    print_data();
    return 0;
}
