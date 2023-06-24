///IMPLEMENTATION OF A QUEUE

#include<iostream>
using namespace std;

const int max_size = 10;
int front = -1;

struct node{
	string data;
	node * next;
};

struct node * frontNode = new node();

struct node * getNode(string data){
	struct node * x = new node();
	x->data = data;
	x->next = NULL;
	return x;
}

void queue(string data){
    if(!(front < max_size))
    {
    	cout<<"Full"<<endl;
    	return;
    }


	if (front==-1){
    frontNode->next = NULL;
    frontNode->data = data;
    front++;
     }else{
     	node * s = new node();
     	s->next = frontNode;
     	s->data = data;
     	frontNode = s;
     	front++;
     }

     	
     
}

string dequeue(void){
	if(front == -1){
		cout<<"Empty"<<endl;
		return "err";
	}
	node * temp = frontNode->next;
	string data = frontNode->data;
	frontNode = temp;
	temp = NULL;
	free(temp);
	return data;
}

void display_all(void){
     if(front == -1){
     	cout<<"Empty"<<endl;
     	return;
     }
int x = 0;
     while(frontNode){
     	cout<<frontNode->data<<endl;
     	frontNode = frontNode->next;
     }
     //cout<<frontNode->next;
}

bool isEmpty(){
	if(front == -1)
		return true;
	else
		return false;
}

bool isFull(){
	if(front == max_size-1)
		return true;
	else
		return false;
}

int main(){

	return 0;
}
