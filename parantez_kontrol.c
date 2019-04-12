#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_SIZE 1000
#define MAX_STACK_SIZE 1000

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
	stk -> top = NULL;
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
		struct node *temp = stk->top;
		stk->top = stk->top->next;
		int x = temp->data;
		free(temp);
		stk->cnt--;
		return x;
	}
	else 
		printf("Stack is empty\n");
}

int match_parentheses(char c1, char c2){
	
	if (c1 == '(' && c2 == ')') return 1;
	else if (c1 == '{' && c2 == '}') return 1;
	else if (c1 == '[' && c2 == ']') return 1;
	else return 0;
	
}

int parentheses_detection(stack* stk, char *file_name){

	FILE* file;
	file = fopen(file_name, "r");

	while( !feof(file) ){
		char c = (char) fgetc(file);
		if(c == '(' || c == '{' || c == '[')
			push(stk, c);
			
		else if(c == ')' || c == '}' || c == ']'){
			if(stk->cnt == 0){
				printf("parentheses not correct!\n");
				return 0;
			}
			if( match_parentheses( pop(stk), c ) == 0 ){
				printf("parentheses not correct!\n");
				return 0;
			}
		}
		
	}

	if(stk->cnt == 0){
		printf("parentheses are correct!\n");
		return 1;
	}
	else{
		printf("parentheses not correct!\n");
		return 0;
	}
}

int main(){
	stack stk;
	initialize(&stk);
	parentheses_detection(&stk, "deneme.c");
}
