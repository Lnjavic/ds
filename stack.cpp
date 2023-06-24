#include<iostream>
using namespace std;
#define MAX 5
int size = 0;

struct node{
	int items[MAX];
	int top; 
	};

int Full(node *s){
	   if(s->top == MAX-1){
		   return 1;
	   }else{
	        return 0;
	   }
	}
	
int Empty(node *s){
	   if(s->top == -1){return 1;}else{return 0;}
	}

int insert(node *s,int x){
	if(!Full(s)){
	  s->top++;
	  s->items[s->top] = x;
	}
	  return 0;
	}
	
int pop(node *s){
	  if(!Empty(s)){
		   s->items[s->top] = NULL;
		    s->top--;
		  }
		  return 0;
	}
	
int showAll(node * s){
	     int n = 0;
	     while(s->items[n] != NULL){
			    cout << s->items[n]<<" "<<"("<<n<<")"<<" ";
			    n = n+1;
			 }
			 return 0;
	}

int main(){
	struct node * stack = new node();
	stack->top = -1;
	
	insert(stack,3);
	insert(stack,4);
	insert(stack,5);
	insert(stack,6);
	insert(stack,7);
	pop(stack);
	pop(stack);
	showAll(stack);
	  return 0;
	}
