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
		   int x = 0;
		   int j = 1;
		   
		   int top_c = s->top+1;
		   
		   while(x < top_c && j < top_c){
					       s->items[x] = s->items[j];
			     x++;
			     j++;
			   }
		    s->top--;
		  }
		  return 0;
	}
	
int showAll(node * s){
	     int n = 0;
	     while(n < s->top+1){
			    cout <<"["<< s->items[n]<<"]";
			    n = n+1;
			 }
			 return 0;
	}

int main(){
	struct node * stack = new node();
	stack->top = -1;
	
	insert(stack,1);
	insert(stack,2);
	insert(stack,3);
	insert(stack,4);
	insert(stack,5);
	pop(stack);
	pop(stack);
	showAll(stack);
	  return 0;
	}
