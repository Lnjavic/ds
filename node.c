#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * A;

int main(){
   A = NULL;

   struct Node* temp;
   temp = (Node*)malloc(sizeof(struct Node));

   printf("%d",temp);
}