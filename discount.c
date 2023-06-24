#include<stdio.h>
int calcDiscount(float x){
  float discount;
  float netAmount;

  if(x>=10000 && x<150000){
  discount = 0.1;
  }

  if(x>=15000 && x<25000){
  discount = 0.15;
  }

  if(x>=25000 && x<30000){
  discount = 0.2;
  }

  if(x>=30000){
  discount = 0.25;
  }

  netAmount = x - (discount*x);

  return netAmount;
	
}

int main(){
	float amount,netPrice;
	printf("Enter the amount spent\n");
	scanf("%f",&amount);

	netPrice = calcDiscount(amount);
	printf("Your net amount to pay is %0.2f\n",netPrice);
}