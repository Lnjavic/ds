//IMPLEMENTATION OF A LINKED LIST ADT
#include<iostream>
using namespace std;

struct node{
	string data;
	node * next;
};

struct node * head = NULL;

class linkedlist{
	public:
	struct node* newnode(){
		struct node * a = new node();
		a->next = NULL;
		return a;
	}

	void insertFirst(string a){
		if(head == NULL){
		  head = new node();
            head->data = a;
          }else{
          	
            struct  node * temp = head;
          head = newnode();
          head->data = a;
          head->next = temp;
        }
	}

	void insertLast(string a){
struct node * temp = new node();
		if(head == NULL){
          head = newnode();
			head->data = a; 
		}else{
			temp = head;
			while(temp->next != NULL){
             	temp = temp->next;
             }
             struct node * last = newnode();
           last->data = a;
           temp->next = last;
		}
	}

	void insertAfter(int pos,string data){
		struct node * temp = new node();
		struct node* tempn = new node();
		struct node * tempc = new node();
		int counter = 0;
		if(head == NULL){
			cout << "Empty";
		}else{
            temp = head;
			while(counter < pos){
				if(temp->next != NULL) temp = temp->next;
				counter++;
			}
			tempn = temp->next;
			tempc->next = tempn;
			tempc->data = data;
			temp->next = tempc;
		}
	}

	void insertBefore(int pos,string data){
		struct node * temp = new node();
		struct node* tempn = new node();
		struct node * tempc = new node();
		int counter = 0;
		if(head == NULL){
			cout << "Empty";
		}else if(pos < 1){
			insertFirst(data);
		}else{
            temp = head;
			while(counter < pos-1){
				if(temp->next != NULL)temp = temp->next;
				counter++;
			}
			tempn = temp->next;
			tempc->next = tempn;
			free(tempn);
			tempc->data = data;
			temp->next = tempc;
		}
	}

	bool isEmpty(){
		if(head == NULL){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		int size = 0;
		struct node * temp = new node();
		temp = head;
		if(temp != NULL){
			while(temp != NULL){
				temp = temp->next;
				size++;
			}
		}
		return size;
	}

   void removeAfter(int pos){
		struct node * temp = new node();
		struct node* tempn = new node();
		int counter = 0;
		if(head == NULL){
			cout << "Empty";
		}else if(pos < 0){
				removeFirst();
		}else{
            temp = head;
			while(counter < pos){
				if(temp->next->next != NULL)temp = temp->next;
				counter++;
			}
			tempn = temp->next->next;
			free(temp->next);
			temp->next = tempn;
		}
	}

	void removeFirst(void){
		if(head == NULL){
			cout<<"Empty"<<endl;
		}else{
			struct node * temp = new node();
			temp = head->next;
			free(head);
			head = temp;
		}
	}


	void swapElements(node ** headref,string a,string b){
		if(a == b)
			return;
		struct node * prevA = NULL;
		struct node * currA = *headref;

		while(currA && currA->data != a){
			prevA = currA;
			currA = currA->next;
		}

		struct node * prevB = NULL;
		struct node * currB = *headref;

		while(currB && currB->data != b){
			prevB = currB;
			currB = currB->next;
		}

		//cout<<prevA->data;
		//cout<<prevB->data<<endl;
		if(currA == NULL || currB == NULL)
			return;

		if(prevA != NULL)
			prevA->next = currB;
		else
			*headref = currB;

		if(prevB != NULL)
			prevB->next = currA;
		else
			*headref = currA;

		struct node * temp = currB->next;
		currB->next = currA->next;
		currA->next = temp;

	}



	int display(){
		if(head == NULL){
			cout<<"Empty\n";
		}else{
		while(head != NULL){
			cout<<" "<<head->data<<"\n";
			head = head->next;
		}
	}
		return 1;
	}
};


int main(){
	linkedlist list;
	list.insertFirst("Arsenal");
	list.insertFirst("Man city");
	list.insertFirst("Newcastle");
	list.insertFirst("Man U");
	list.insertFirst("Spurs");
	list.insertLast("Brentford");
	list.insertLast("Brighton");
	list.swapElements("Brighton","Spurs");
	//list.insertLast(3);
	//list.removeAfter(0);
	list.display();
	return 0;
}
