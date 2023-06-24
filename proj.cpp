#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node*link;
};
 
 struct Node * head;

 void Insert(int x){
   Node* temp = (Node*)malloc(sizeof(struct Node));
   temp->data = x;
   temp->link = head;
   head = temp;
 };
 void Print(){
   struct Node* temp = head;
   printf("List is : ");
   while(temp != NULL){
      printf("%d",temp->data);
      temp = temp->link;
   }
   printf("\n");
 };


 int main(){
   head = NULL;
    printf("How many numbers \n");
    int n , i , x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      printf("Enter number \n");
      scanf("%d",&x);
      Insert(x);
      Print();
    }
 }