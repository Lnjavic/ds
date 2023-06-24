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
	queue(int x){
        front = rear = -1;
        size = x; 
        array = new node * [size* sizeof(node*)];

        for(int i=0;i<size;++i){
        	array[i] = NULL;
        }
	}
};

bool isempty(queue * x){
	return x->front == -1;
}

bool isfull(queue * x){
	return x->rear == x->front-1;
}

bool hasonlyone(queue * x){
    return x->front == x->rear;
}

void enqueue(node * root,queue * queue){
      if(isfull(queue))
      	return;

      queue->array[++queue->rear] = root;

      if(isempty(queue))
      	queue->front++;
}

node * dequeue(queue * queue){
	if(isempty(queue))
		return NULL;
	node * temp = queue->array[queue->front];

	if(hasonlyone(queue)){
		queue->front = queue->rear = -1;
	}
	return temp;
}

node * getfront(queue * x){
	return x->array[x->front];
}

bool hasbothchild(node * temp){
	return temp && temp->left && temp->right;
}

void insert(node ** root,queue * queue,int data){
	node * temp = new node(data);
	if(!*root){
		*root = temp;
	}else{
		node * front = getfront(queue);
		if(!front->left)
			front->left = temp;
		else if(!front->right)
			front->right = temp;
		if(hasbothchild(front))
			dequeue(queue);
	}

	enqueue(temp,queue);
}

void levelorder(node * root){
	queue * que = new queue(50);
	enqueue(root,que);
	while(!isempty(que)){
		node * temp = dequeue(que);
		cout<<temp->data<<" ";
		if(temp->left)
			enqueue(temp->left,que);
		if(temp->right)
			enqueue(temp->right,que);
	}
}

void printarray(queue* c){
	for(int i=0;i<40;i++)
	   cout<<c->array[i]->data<<" ";

}

void preorder(node * c){
	if(c != NULL){
	cout<< c->data<<" ";
	preorder(c->left);
	preorder(c->right);
}
}

int main(){
	queue * x = new queue(50);
	node * root = NULL;
	int i;
	for(i=1;i<=40;i++){
		insert(&root,x,i);
	}
	levelorder(root);
	//preorder(x->array[x->front]);

	return 0;
}

