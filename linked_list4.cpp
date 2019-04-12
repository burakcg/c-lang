#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* addToList(struct node* root, int x){
	struct node* temp = (struct node *) malloc(sizeof(struct node));
	temp->data = x;
	temp->next = root;
	struct node*iter=root;
	
	if(root == NULL){
		temp->next=temp;
		return temp;
	}
		
	else if(temp->data<root->data){
		if(root->next!=root){
			while(iter->next!=root){
				iter=iter->next;
			}
			temp->next=root;
			iter->next=temp;
			return temp;
		}
		temp->next=root;
		root->next=temp;
		return temp;
	}


	while(iter->next != root && iter->next->data < temp->data){
		iter = iter->next;
	}
	
	temp->next = iter->next;
	iter->next = temp;
	
	return root;
}

void print(struct node* root){
	struct node* temp = root;
	do{
		printf("%d\n",temp->data);
		temp=temp->next;
		
	}while(temp!=root);
	
}

struct node* delete_b(struct node* root,int x){
	struct node* temp;
	struct node* iter;
	
	
	if(root==NULL)
		printf("list is empty");
		
	else if(root->data==x){
		
		iter=root;
		while(iter->next!=root)
			iter=iter->next;
		
		iter->next=root->next;
		temp=root;
		root=root->next;
		free(temp);
		return root;
	}
	iter=root;
	while(iter->next!=root && iter->next->data!=x){
		iter=iter->next;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return root;
	
}

int min_b(struct node* root){
	struct node*iter=root;
	int min=root->data;
	
	while(iter->next!=root){
		if(iter->data<min)
			min=iter->data;
			
			iter=iter->next;
	}
	return min;
}
//Listenin baþýndaki eleman ile sonundaki elemaný toplayýp listenin sonuna ekleyen fonksiyon.
struct node* add_b(struct node* root){
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=root;
	struct node*iter=root;
	
	while(iter->next!=root){
		iter=iter->next;
	}
	temp->data=root->data+iter->data;
	temp->next=root;
	iter->next=temp;
	return root;

}



int main(){
	struct node* root = NULL;
	root = addToList(root, 5);
	root = addToList(root, 3);
	root = addToList(root, 6);
	root = addToList(root, 7);
	root = addToList(root, 1);
	root = addToList(root, 11);
	root=delete_b(root,11);
	print(root);
	printf("min:%d\n",min_b(root));
	add_b(root);
	printf("xxxxxxxx\n");
	print(root);
}
