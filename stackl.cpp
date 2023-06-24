#include<iostream>
using namespace std;

struct node{
	int data;
	int top = -1;
	struct node * below;
	};

struct node * topmost = new node();
int Empty(){
	   if(topmost->top == -1){return 1;}else{return 0;}
	}

int Full(){
	   if(topmost->top == 10){return 1;}else{return 0;}
	}
void push(int x){
	    struct node * temp = new node();
	    if(topmost == NULL){
	    temp->data = x;
	    temp->below = NULL;
	    temp->top++;
	     topmost = temp;
          }else{
			  temp->data = x;
			  temp->below = topmost;
			  temp->top = topmost->top+1;
			  topmost = temp;
			  }
	   
	}

void poP(){
	struct node * temp = new node();
	  if(topmost->below != NULL){
		  int a = topmost->top;
		    temp = topmost->below;
		    cout<<a<<endl;
		    topmost = temp;
		    
		  }else if(topmost->below == NULL && topmost != NULL){
			   topmost = NULL;
			   cout<<"cleared";
			   
			  }
	}

int main(){
	topmost->top = -1;
	push(3);
	push(4);
	push(5);
	poP();
	poP();
	poP();
	poP();
	push(7);
	cout<<topmost->data;
	return 0;
	}
