#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* addToList(struct node* root, int x){
	struct node* temp = (struct node *) malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	
	if(root == NULL)
		return temp;
	
	else if(temp->data <= root->data){
		temp->next = root;
		return temp;
	}
	
	struct node* iter = root;
	
	while(iter->next != NULL && iter->next->data < temp->data){
		iter = iter->next;
	}
	
	temp->next = iter->next;
	iter->next = temp;
	
	return root;
}

void print(struct node* root){
	while(root!=NULL){
		printf("%d\n",root->data);
		root=root->next;
	}
}


struct node* delete_b(struct node* root,int x){
	if(root==NULL)
		printf("list is empty");
		
	
	else if(root->data==x){
	
		struct node*temp=root;
		root=root->next;
		free(temp);
		return root;
	}
	
	else{
		struct node*iter=root;
		struct node*temp=NULL;
		while(iter!=NULL && iter->next->data!=x){
			iter=iter->next;
					
	}
		temp=iter->next;
		iter->next=iter->next->next;
		free(temp);
			
		return root;
	}
	
}	
 

int main(){
	struct node* root = NULL;
	root = addToList(root, 5);
	root = addToList(root, 1);
	root = addToList(root, 6);
	root = addToList(root, 7);
	root = addToList(root, 3);
	root = addToList(root, 11);
	delete_b(root,5);
	
	print(root);
	

}
