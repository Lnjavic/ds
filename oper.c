#include<stdio.h>

void main(){
int num1,num2,add,sub,mult;
float div;

printf("Enter a number\n$ ");
scanf("%d",&num1);
printf("Enter second number\n$ ");
scanf("%d",&num2);

add = num1+num2;
sub = num1-num2;
mult = num1*num2;
div = (float)num1/(float)num2;

printf("%d + %d = %d\n",num1,num2,add);
printf("%d - %d = %d\n",num1,num2,sub);
printf("%d * %d = %d\n",num1,num2,mult);
printf("%d / %d = %0.2f\n",num1,num2,div);

}
