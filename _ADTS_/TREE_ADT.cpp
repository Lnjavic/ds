//IMPLEMENTATION OF A TREE ADT

#include<iostream>
using namespace std;

class node{
public:
	int data;
	node * left;
	node * right;
	node(int x){
		data = x;
        left = NULL;
        right = NULL;
	}
};

class queue{
public:
	int front;int rear;
	int size;
	node ** array;
}

void traversePOSTorder(node * s){
	if(s != NULL){
        traversePreorder(s->left);
        traversePreorder(s->right);
        cout << " "<<s->data;
    }
}

void traverseINordeR(node * s){
	if(s != NULL){
        traversePreorder(s->left);
        cout << " "<<s->data;
        traversePreorder(s->right);
    }
}

void traversePREorder(node * s){
	if(s != NULL){
        cout << " "<<s->data;
        traversePreorder(s->left);
        traversePreorder(s->right);
    }
}

int main(){
   node * root = new node(1);
   root->left = new node(2);
   root->right = new node(7);
   root->right->left = new node(8);
   root->left->right = new node(4);
   root->left->left = new node(3);
   traversePREorder(root);
   return 0;
}