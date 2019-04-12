#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

struct node{
	int data;
	struct node *next;
};

typedef struct{
	int cnt;
	struct node *top;	
}stack;

void initialize(stack *stk){
	stk->cnt = 0;
	stk->top = NULL;
}

void push(stack* stk, int c){
	if (stk->cnt == MAX_STACK_SIZE){
		printf("Stack is full\n");
		return;
	}
	else {
		struct node *temp = (struct node*) malloc(sizeof(struct node));
		temp->data = c;
		temp->next = stk->top;
		stk->top = temp;
		stk->cnt++;
	}
}

int pop(stack *stk){
	if(stk->cnt != 0){
		struct node* temp = stk->top;
		stk->top = stk->top->next;
		int x = temp->data;
		free(temp);
		stk->cnt--;
		return x;
	}
	else 
		printf("Stack is empty\n");
}


int main(){
	stack stk;
	
	initialize(&stk);
	
	push(&stk, 5);
	printf("%d\n",pop(&stk));
}
