#include<stdio.h>
#include<stdlib.h>

struct node{
   int expo;
   int coef;
  	struct  node *  next;
}
;
struct node * getNode(int coef,int expo){
	struct node * temp =(struct node* )malloc(sizeof(struct node));
	temp->expo = expo;
	temp->coef = coef;
	temp->next = NULL;
	return temp;

}

void display(struct node * s){
	while(s != NULL){

	printf("%dY^%d + ",s->coef,s->expo);
	s = s->next;
	}
}

void swap(struct node * a,struct node * b){
	int tempx = a->expo;
	int tempc = a->coef;
	a->expo = b->expo;
	a->coef = b->coef;
	b->expo = tempx;
	b->coef = tempc;
}

void sort(struct node * head){
	struct node * temp;
	struct node * lastpointer = NULL;
	int swapped;

do{

	temp = head;
	swapped = 0;

	while(temp->next != lastpointer){
         if(temp->expo > temp->next->expo){
         	swap(temp,temp->next);
         	swapped = 1;
         }
		temp = temp->next;
	}

	lastpointer = temp;

}while(swapped);


}

struct node * addpolys(struct node * a,struct node *b){
	struct node * poly = (struct node*)malloc(sizeof(struct node));
	struct  node * temp = poly;

	while(a->next && b->next){
		if(a->expo > b->expo){
			poly->expo = a->expo;
			poly->coef = a->coef;
			a = a->next;
		}else if(a->expo < b->expo){
			poly->expo = b->expo;
			poly->coef = b->coef;
			b = b->next;
		}else{
			poly->expo = a->expo;
			poly->coef = a->coef + b->coef;
			a = a->next;
			b = b->next;
		}
		poly->next = (struct node*)malloc(sizeof(struct node));

		poly = poly->next;
		poly->next = NULL;
}

while(a->next || b->next){
	if(a->next){
        poly->expo = a->expo;
        poly->coef = a->coef;
        a = a->next;
	}
	if(b->next){
		poly->expo = b->expo;
		poly->coef = b->coef;
		b = b->next;
	}

	poly->next = (struct node*)malloc(sizeof(struct node));

		poly = poly->next;
		poly->next = NULL;
}




	return temp;

}

int main(){

struct node * head = getNode(2,70);
head->next = getNode(2,23);
head->next->next = getNode(-2,1);
head->next->next->next = getNode(-2,6);
head->next->next->next->next = getNode(2,20);

struct node * head2 = getNode(5,7);
head2->next = getNode(8,24);
head2->next->next = getNode(-2,1);
head2->next->next->next = getNode(-2,67);
head2->next->next->next->next = getNode(2,2);

printf("\nBefore : ");
display(head);
//sort(head);
//sort(head2);
printf("\nAfter sorting : ");
display(head2);
printf("\nAfter Addition : ");
struct node * Addition = addpolys(head,head2);
display(Addition);
return 0;

}
