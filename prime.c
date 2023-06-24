#include <stdio.h>

void main(){
int a,b,c=0;
printf("Enter a number\n");
scanf("%d",&a);

for (b=2;b<a;++b){
if((a % b) == 0){
c = 1;
break;
}
}

if(c==0){
printf("%d is prime number\n",a);
}else{
printf("%d is not prime number\n",a);
}

}
