#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node * left;
     struct node * right;
 };

 struct node * getnode(int data){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    return temp;
}


void inorder(struct node * s,int i){
	if(s){
		i=i+1;
		//printf("%d  ",s->data);
		printf("%d ", i);
		inorder(s->left,i);
		inorder(s->right,i);
	}
}

 int main(){
    struct node * root = getnode(100);
    
    root->left = getnode(75);
    root->right = getnode(50);
    root->left->right = getnode(25);
    root->left->left = getnode(0);
    inorder(root,0);
 	return 0;
 }