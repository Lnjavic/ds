#include<stdio.h>

void main(){
float rate = 119.84;
float dollars,shillings;

printf("Enter amount to convert in KSH \n");
scanf("%f",&shillings);
dollars = shillings/rate;
printf("%0.2f is %0.2f Dollars\n",shillings,dollars);
}
