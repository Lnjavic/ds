#include<iostream>
using namespace std;

struct Node {
	int data;
	Node * next;
};



struct Node * head = NULL;


void insert(int x){
	
	struct Node* temp;
	
	temp = new Node();
	
	  if(head == NULL){
		  temp->data = x;
		  temp->next = NULL;
		  head = temp;
		  }else{
			  temp->data = x;
			  temp->next = head;
			  head = temp;
		  }
	
	}
	
	int displayAll(){
		Node * p = head;
		while(p != NULL){
			cout<<p->data<<" ";
			p = p->next;
		}
		return 0;
	}

int addEnd(int c){
	
	Node * q = head;
	
	if(q == NULL){
	     head = new Node();
	     head->data = c;
	     head->next = NULL;
	     return 0;
	}
	
	while(q != NULL){
		if(q->next == NULL){
			   q->data = c;
			}
			q = q->next;
		}
	return 0;
	}

int showLength(){
	int length = 0;
	   Node * L = head;
	   if(L != NULL)
	   {
		   while(L != NULL){
			      length++;
			      L=L->next;
			   }
	        	   
		   }
		   
		   cout <<"length "<<length<<endl;
		   
		   return 0;
	}
	
int popFront(){
	   Node * p = head;
	   Node * todelete;
	   
	   while(p->next->next != NULL){
		   cout << "making" <<endl;
		  
		       p = p->next;
		   }
		   todelete = p->next;
		   delete todelete;
		   p->next = NULL;
		   
	   
	    cout << "deleted"<<endl;
	    return 0;
	}
	
int popEnd(){
	
	     Node * f = head;
	     
	     if(head == NULL)
	     {
			 cout << "Empty List"<<endl;
	     }else{
			    head = head->next;
			    delete f;
			 }
	     
	return 0;
	}
	
int popMid(int index){
	
	   Node * M = head;
	   
	   if(M == NULL){
		     cout << "List Empty"<<endl;
		   }else if(M->next == NULL){
			       popFront();
			   }else{
		    
		        for(int i = 2;i<index;i++){
					  if(M->next != NULL) {
						  if(M->next->next != NULL) M = M->next;
					  }else{
						  popEnd();
						     break;
						  }
					} 
		     M->next = M->next->next;
		    }
	   return 0;
	}
	
int deleteData(int x){
	
	Node * temp = head,*prev;
	bool found = true;
	
	if(temp == NULL){
		   cout << "<list empty"<<endl;
		}else if(temp->data == x){
			     head = head->next;
			     free(temp);
			}else{
				
				while(temp != NULL && temp->data != x){
					
					   prev = temp;
					   if(temp->next != NULL){
					   temp = temp->next;
				        }else if(temp->next == NULL && temp->data != x){
							    found = false;
							   cout << "Not Found"<<endl;
							   break;
							}else{
							popEnd();
							break;
							}
					
					}
					
					prev->next = temp->next;
					cout<<"hey:";
					
					if(found) free(temp);
				
				}
	
	return 0;
	}

int main(){
	//insert(1);
	/*insert(2);
	insert(3);
	insert(4);
	insert(5);*/

addEnd(50);

//popFront();
//popFront();
//popEnd();

//popMid(1);
//popMid(1);

//deleteData(1);

showLength();

displayAll();

 
 return 0;
}


