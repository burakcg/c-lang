#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node* add(struct node* root,int x){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(root==NULL){
		return temp;
	}
	else if(temp->data > root->data){
		temp->next = root;
		root->prev = temp;
		return temp;
	}
	else{
		struct node* iter = root;
		while(iter->next!=NULL && iter->data > temp->data){
			iter = iter->next;
		}
		temp->prev = iter->prev;
		temp->next = iter;
		iter->prev->next = temp;
		iter->prev = temp;	
		
		return root;
	}
}
	
void print(struct node* root){
	while(root!=NULL){
		printf("%d\n",root->data);
		root = root->next;
	}
}
void print_reserve(struct node* root){
	while(root->next!=NULL)
		root = root->next;
		
	while(root!=NULL){
		printf("%d\n",root->data);
		root = root->prev;
	}	
	
	
	
}


struct node* delete_node(struct node* root,int x){
	struct node* temp;
	struct node* iter;
	if(root==NULL)
		printf("list is empty");
	
	if(root->data==x){
		temp = root;
		root = root->next;
		root->prev = NULL;
		free(temp);	
		return root;
	}
	
	iter = root;
	while(iter->next!=NULL && iter->data!=x)
		iter = iter->next;
	
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	free(iter);
	
	return root;
}
	
int main(){
	struct node* root = NULL;
	root = add(root,5);
	root = add(root,8);
	root = add(root,13);
	print_reserve(root);
	root = delete_node(root,13);
	print(root);
}
