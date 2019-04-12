#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct node{
	int data;
	struct node* next;
};

typedef struct{
	int cnt;
	struct node* front;
	struct node* rear;
}queue;

void initialize(queue *stk){
	stk->cnt = 0;
	stk->front = NULL;
	stk->rear = NULL;
}

void enqueue(queue* que, int c){
	if(que->cnt == MAX_QUEUE_SIZE){
		printf("queue is full\n");
		return;
	}
	else{
		struct node* temp = (struct node*) malloc(sizeof(struct node));
		temp->data = c;
		temp->next = NULL;
		
		if(que->cnt == 0){
			que->front = temp;
			que->rear = temp;
		}
		else{
			que->rear->next = temp;
			que->rear = temp;
		}
		que->cnt++;
	}
}

int dequeue(queue* que){
	if(que->cnt == 0){
		printf("queue is empty\n");
	}
	else{
		struct node* temp = que->front;
		que->front = temp->next;
		que->cnt--;
		
		int x = temp->data;
		free(temp);
		return x;
	}
}
int isempty(queue* que){
	if(que->cnt==0)
		return 1;
	else
		return 0;
}
int isfull(queue* que){
	if(que->cnt==MAX_QUEUE_SIZE)
		return 1;
	else
		return 0;
}

int main(){
	queue que;	
	initialize(&que);
	
	enqueue(&que, 6);
	enqueue(&que, 3);
	enqueue(&que, 1);
	enqueue(&que, 8);
	
	
	printf("%d\n", dequeue(&que));
	printf("%d\n", dequeue(&que));
	printf("%d\n", dequeue(&que));
	
	
	if(isempty(&que)==1)
		printf("queue is empty\n");
	
	else
		printf("queue is not empty\n");
		
	if(isfull(&que)==1)
		printf("queue is full\n");
		
	else
		printf("queue is not full\n");
	
	
	
}
