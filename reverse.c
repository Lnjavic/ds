#include<stdio.h>

void main(){
	int a;
	int b = 1;

	printf("Enter a number>> \n");
	scanf("%d",&a);

	while(a>0){
		printf("%d ",a);
		b = b*a;
		a = a - 1;

	}
	printf("\nProduct = %d\n",b);
}