#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node* addfront(struct node* head, int x){
//	struct node *temp=new node();
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL){
		temp->next=NULL;
		return temp;
	}
	temp->next=head;
	return temp;
	//

}

struct node *addlast(struct node *head,int x){
//	struct node *temp=new node();
	struct node *temp=NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
		if(head==NULL){
			head=temp;
			return head;
	}
	struct node *last=head;
		while(last->next!=NULL){
		last=last->next;
	}
	last->next=temp;
	return head;
}
void print_list(struct node *head){
	if(head==NULL){
		printf("List is empty");
	}
	else{
		while(head!=NULL){
			printf("%d\t",head->data);
			head=head->next;
		}
	}
}

void print_list_reverse(struct node *head){
	if(head==NULL){
		return;
	}
	print_list_reverse(head->next);
    printf("%d\t",head->data);

}

int count(struct node *head){
	int counter=0;
	while(head!=NULL){
		counter++;
		head=head->next;
	}
	return counter;
}


struct node *del(struct node *head,int key){

	if (head==NULL){
		printf("Liste bos");
		return 0;
	}

	struct node *temp=head;

	if (head->data==key){
		head=head->next;
		free(temp);
	}
	else{
		while(temp->next->data!=key){
			temp=temp->next;
		}
		struct node* deleted=temp->next;
		temp->next=temp->next->next;
		free(deleted);
	}
	return head;
}


int main(){
	struct node* head= NULL;
	head = addlast(head,7);
	head=addlast(head,1);
	head=addlast(head,4);
	head=addlast(head,70);
	
	head = addfront(head, 5);
	
	print_list(head);
	printf ("\n");
	print_list_reverse(head);
	printf("\nNumber of nodes=%d",count(head));
	head=del(head,4);
	printf("\n");
	print_list(head);

}

