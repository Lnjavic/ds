//implementation of a stack ADT

#include<iostream>
using namespace std;

const int max_size = 10;
int top = -1;

struct node{
	string data;
	node * next;
};

struct node * topNode = new node();
//create and return a node with data assigned
struct node * getNode(string data){
	struct node * x = new node();
	x->data = data;
	x->next = NULL;
	return x;
}
//push a node in the stack
void push(string data){
    if(!(top < max_size))
    {
    	cout<<"Full"<<endl;
    	return;
    }


	if (top==-1){
    topNode->next = NULL;
    topNode->data = data;
    top++;
     }else{
     	node * s = new node();
     	s->next = topNode;
     	s->data = data;
     	topNode = s;
     	top++;
     }

     	
     
}
//remove a node from the stack
string pop(void){
	if(top == -1){
		cout<<"Empty"<<endl;
		return "err";
	}
    node * temp = topNode;
	while(temp->next->next != NULL){
        temp = temp->next;
    }
    string x = temp->next->data;
    temp->next = NULL;
    free(temp->next);
    //cout<<"XXX "<<temp->data<<endl;
    //temp = NULL;
    //free(temp);
    return x;
}
//display all the data in the stack
void display_all(void){
     if(top == -1){
     	cout<<"Empty"<<endl;
     	return;
     }
int x = 0;
     while(topNode){
     	cout<<topNode->data<<endl;
     	topNode = topNode->next;
     }
     //cout<<topNode->next;
}
//check if stack is empty
bool isEmpty(){
	if(top == -1)
		return true;
	else
		return false;
}
//check if stack is full
bool isFull(){
	if(top == max_size-1)
		return true;
	else
		return false;
}

int main(){
    push("Arsenal");
    push("Chelsea");
    push("Everton");
    push("Ajax");
    push("Barcelona");
    pop();
    push("New");
    display_all();

	return 0;
}
