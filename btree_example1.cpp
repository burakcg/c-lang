#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node btree;
	
btree* new_node(int x){
	btree* temp = (btree*)malloc(sizeof(btree));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

btree* insert(btree* root,int x){
	if(root==NULL)
		return new_node(x);
	
	else if(x<root->data)
		root->left = insert(root->left,x);
		
	else
		root->right = insert(root->right,x);
		
		return root;
}

void inorder(btree* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
		
	
}

btree* minimum_b(btree* root){
	if(root->left==NULL)
		return root;
		
	minimum_b(root->left);
		

}

btree* delete_b(btree* root,int x){
	if(root==NULL)
		return root;
		
	if(x<root->data)
		root->left = delete_b(root->left,x);
	
	else if(x>root->data)
		root->right = delete_b(root->right,x);
	
	else{
				
		if(root->left == NULL){
			btree* temp = root->right;
			free(root);
			return temp;
			
		}
		else if(root->right == NULL){
			btree* temp = root->left;
			free(root);
			return temp;
		}
		else{
			btree* temp = minimum_b(root->right);
			root->data = temp->data;
			root->right = delete_b(root->right,temp->data);
		}
			
		
	}
return root;
}

int height(btree*root){
	
	if(root==NULL)
		return -1;
	
	else{
		int lheight, rheight;		
		lheight=height(root->left);
		rheight=height(root->right);
		
		if(lheight>rheight)
			return lheight+1;
		
		else
			return rheight+1;
			
			
	}
		
}	

int nleaves(btree* root){
	if(root==NULL)
		return 0;
	else if(root->right==root->left)
		return 1;
	else
		return nleaves(root->left)+nleaves(root->right);
}

int count(btree*root){
	if(root==NULL)
		return 0;
	
	return 1+count(root->left)+count(root->right);
}

btree* change(btree* root, btree* min){
	if(root==NULL)
		return root;
	
	else{
		root->data=min->data;
		change(root->left, min);
		change(root->right, min);
	}
}

btree* swap(btree* root){
	btree*temp = NULL;
	
	if(root!=NULL){
		swap(root->left);
		swap(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
				
	}
		return root;
		
}
//Root'un BST'deki bir elemana olan uzaklýðýný bulan fonksiyon.	
int depth_b(btree* root ,int x){
	if(root==NULL)
		return -1;
	
	else{
		int depth =0;
		if(x<root->data)
			depth = 1+depth_b(root->left, x);
			
		else if(x>root->data)
			depth = 1+depth_b(root->right, x);
		
		else{
			return depth;
		}	
			
	}
	
}	
//BST'deki çift deðerleri tek, tekleri çift yapan fonksiyon.
btree* change_b(btree* root){
	if(root==NULL)
		return root;
		
	if(root->data%2==0)
		root->data-=1;
	
	else
		root->data+=1;
	
	change_b(root->right);
	change_b(root->left);
	
}



void kat(btree *root){
    
    if(root== NULL)
    	return;
    if(root->left != NULL && root->right != NULL)
    {
    	if( root->data*2 == root->right->data)
	 			printf("%d\n",root->data);
	 	kat(root->left);
 	 	kat(root->right);
	}
	 	if(root->right != NULL || root->left != NULL){
	 	if(root->right == NULL)
	 		kat(root->left);
		else if(root->left == NULL ){
	 		if(root->right != NULL && root->data*2 == root->right->data)
           		 printf("%d\n",root->data);
		   kat(root->right);
       } 
	}	
}

int sum_b(btree* root){
	if(root==NULL)
		return 0;
	
	else
		return root->data+sum_b(root->left)+sum_b(root->right);
}

void leftchild(btree *root){
	
	if(root != NULL){
		if(root->left != NULL && root->right == NULL)  
			printf("%d\n",root->data);
		
		leftchild(root->left);
		leftchild(root->right);
}
	else
		return;
		
}

int sumLeaves(btree *root){
    if(root==NULL)
        return 0;
    
	if(root->left ==root->right)
        return root->data;
        	
	return sumLeaves(root->left) +sumLeaves(root->right);
}
		

		
int main(){
	btree* root = NULL;
	root=insert(root,18);
	insert(root,7);
	insert(root,3);
	insert(root,14);
	insert(root,22);
	insert(root,19);
	insert(root,25);
	insert(root,50);
	insert(root,2);	
	
	printf("count: %d\n",count(root));
	printf("yaprak sayisi: %d\n",nleaves(root));
	printf("height: %d\n",height(root));
	printf("depth: %d\n",depth_b(root,14));
	printf("minimum: %d\n",minimum_b(root)->data);
	
	delete_b(root,19);
	inorder(root);
	printf("xxxxxxxxxxx\n");
	
	kat(root);
	printf("xxxxxxxxxxx\n");
	
	printf("sumallnodes: %d\n",sum_b(root));	
	printf("xxxxxxxxxxx\n");
	
	printf("sumallleaves: %d\n",sumLeaves(root));
	printf("xxxxxxxxxxx\n");
	
	leftchild(root);
	printf("xxxxxxxxxxx\n");
	
	swap(root);
	inorder(root);
	printf("xxxxxxxxxxx\n");
	
	change_b(root);
	inorder(root);

}
