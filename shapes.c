#include<stdio.h>

void main(){
    int option;
    float area,radius,base,height,length,width;
printf("choose shape:\n [1] circle\n [2] triangle\n [3] rectangle\n");
scanf("%d",&option);

switch(option){
case 1:
    printf("Enter the radius\n");
    scanf("%f",&radius);
    area = (radius * radius * 22)/7;
    printf("Area = %0.2f\n",area);
    break;
case 2:
    printf("Enter base\n");
    scanf("%f",&base);
    printf("enter height\n");
    scanf("%f",&height);
    area =  (base * height)/2;

    printf("Area = %0.2f\n",area);
    break;
case 3:
    printf("Enter length\n");
    scanf("%f",&length);
    printf("Enter width\n");
    scanf("%f",&width);
    area = width*length;
    printf("Area = %0.2f\n",area);
    break;
default:
    printf("inavalid choice\n");
    break;

}

}
