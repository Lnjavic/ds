#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
	public:
	int coef;
	int expo;
	node * next;
	node(int a,int b){
		coef = a;
		expo = b;
		next = NULL;
	}
};

void insert(node * s,int coef,int expo){
    node * temp = new node(coef,expo);
    while(s->next != NULL)
    	s=s->next;
    s->next = temp;
}

void display(node * s){
   while(s->next != NULL){
   		cout<< s->coef<<"Y^"<<s->expo<<" + ";
   		s = s->next;
   	}
   	cout<< s->coef<<"Y^"<<s->expo<<endl;
}

void sortout(node * start){
   int swapped;
   node * ptr1 = new node(0,0);
   node * lptr = NULL;

   do{
   	swapped = 0;
   	ptr1 = start;

   	while(ptr1->next != lptr){

   		if(ptr1->expo > ptr1->next->expo){
   			swap(ptr1,ptr1->next);
   			swapped = 1;
   		}

   		ptr1 = ptr1->next;
            
   	}
   	lptr = ptr1;

   }while(swapped);
   }

void swap(node * a,node * b){
	int tempcoef = b->coef;
	int expo = b->expo;
	b->coef = a->coef;
	b->expo = a->expo;
	a->expo = expo;
	a->coef = tempcoef;

}

int main(){
	node * first = new node(2,1);
	insert(first,3,3);
	insert(first,1,2);
	node * second = new node(1,1);
	insert(second,3,3);
	insert(second,1,2);
	node * answer;
	//display(first);
	//display(second);
	//add(answer,first,second);
    sortout(second);
    display(second);
	return 0;
}
