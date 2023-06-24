#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
	};
	
struct node *newNode(int data){
	  struct node * n = new node();
	  n->left = NULL;
	  n->data = data;
	  n->right = NULL;
	  return (n);
	}

void traverseInOrder(struct node *temp){
	  if(temp != NULL){
		 
		     traverseInOrder(temp->left);
		      cout << " " << temp->data;
		     traverseInOrder(temp->right);
		  }
	}

int main(){
	struct node * x = newNode(1);
	x->left = newNode(2);
	x->right = newNode(3);
	x->left->left = newNode(4);
	x->left->left->left = newNode(5);
	x->left->left->right = newNode(6);
	traverseInOrder(x);
	return 0;
	}
