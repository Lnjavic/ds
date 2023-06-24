//IMPLEMENTATION OF A DOUBLY LINKED LIST ADT
#include<iostream>
using namespace std;

struct node{
	struct node * prev;
	 int data;
	struct node * next;
	};

struct node * head;
int counter = 0;

class dbl{
	public:
	
	dbl(){
	     head = NULL;
	}
	
	void insertFront(int data){
		   struct node * temp = new node();
		   
		   temp->prev = NULL;
		   temp->data = data;
		   temp->next = NULL;
		   head = temp;
		}
		
	void insertEnd(int a){
		struct node * temp = new node();
		
		if(head == NULL){
		  
		  temp->prev = NULL;
		  temp->data = a;
		  temp->next = head;
		  head = temp;
	        }else{
				    temp->data = a;
				    temp->next = head;
				    head->prev = temp;
				    
				    head = temp;
				    
				
				}
				
		}
		
	void joinEnds(){
		struct node * temp = new node();
		temp = head;
		    while(head->next != NULL){
				
				  head = head->next;
				
				}
				
			temp->prev = head;
			head->next = temp;
			
			head = temp;
		
		}
	
	void displayAll(){
		int x = 0;
		  while(x <= counter){
			     cout<<head->data<<endl;
			     head = head->next;
			     x = x+1;
			  }
		}
		
	void insertCircle(int x){
		     struct node * temp = new node();
		     if(head == NULL){
				    temp->data = x;
				    temp->prev = temp;
				    temp->next = temp;
				    
				    head = temp;
				    
				 }else{
		     temp->next = head->prev;
		     temp->data = x;
		     temp->prev = head->next;
		     head->next = temp;
		     head->prev = temp;
		     
		     head = temp;
		     counter = counter + 1;
		 }
		}
	
	};
	
int main(){
	  dbl linkedList;
	  //linkedList.insertFront(4);
	  //linkedList.insertEnd(1);
	  //linkedList.insertEnd(3);
	  //linkedList.insertEnd(5);
	  //linkedList.insertEnd(7);
	  //linkedList.insertEnd(8);
	 linkedList.insertCircle(77);
	 linkedList.insertCircle(80);
	 linkedList.insertCircle(65);
	 linkedList.insertCircle(90);
	 linkedList.insertCircle(5);
	  linkedList.displayAll();
	  return 0;
	}
