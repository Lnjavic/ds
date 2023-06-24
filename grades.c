#include<stdio.h>

void main(){
char name[50],regNo[50];
int csc111,csc112,csc113,csc115,csc126;
char csc111grd,csc112grd,csc113grd,csc115grd,csc126grd;
printf("Enter your Full name\n");
scanf("%[^\n]s",&name);
printf("Enter your registration NO\n");
scanf("%s",&regNo);
printf("Enter your csc111 marks\n");
scanf("%d",&csc111);

if(csc111 < 40){ csc111grd = 'E';}
if(csc111 >= 40 && csc111 < 50){ csc111grd = 'D';}
if(csc111 >= 50 && csc111 < 60){ csc111grd = 'C';}
if(csc111 >= 60 && csc111 < 70){ csc111grd = 'B';}
if(csc111 >= 70){ csc111grd = 'A';}

printf("Enter your csc112 marks\n");
scanf("%d",&csc112);


if(csc112 < 40){ csc112grd = 'E';}
if(csc112 >= 40 && csc112 < 50){ csc112grd = 'D';}
if(csc112 >= 50 && csc112 < 60){ csc112grd = 'C';}
if(csc112 >= 60 && csc112 < 70){ csc112grd = 'B';}
if(csc112 >= 70){ csc112grd = 'A';}


printf("Enter your csc113 marks\n");
scanf("%d",&csc113);


if(csc113 < 40){ csc113grd = 'E';}
if(csc113 >= 40 && csc113 < 50){ csc113grd = 'D';}
if(csc113 >= 50 && csc113 < 60){ csc113grd = 'C';}
if(csc113 >= 60 && csc113 < 70){ csc113grd = 'B';}
if(csc113 >= 70){ csc113grd = 'A';}


printf("Enter your csc115 marks\n");
scanf("%d",&csc115);


if(csc115 < 40){ csc115grd = 'E';}
if(csc115 >= 40 && csc115 < 50){ csc115grd = 'D';}
if(csc115 >= 50 && csc115 < 60){ csc115grd = 'C';}
if(csc115 >= 60 && csc115 < 70){ csc115grd = 'B';}
if(csc115 >= 70){ csc115grd = 'A';}


printf("Enter your csc126 marks\n");
scanf("%d",&csc126);


if(csc126 < 40){ csc126grd = 'E';}
if(csc126 >= 40 && csc126 < 50){ csc126grd = 'D';}
if(csc126 >= 50 && csc126 < 60){ csc126grd = 'C';}
if(csc126 >= 60 && csc126 < 70){ csc126grd = 'B';}
if(csc126 >= 70){ csc126grd = 'A';}

printf("STUDENT NAME: %s\n",name);
printf("STUDENT REG NO: %s\n\n",regNo);
printf("COURSE CODE  MARKS   GRADE\n");
printf(" CSC111       %d      %c\n",csc111,csc111grd);
printf(" CSC112       %d      %c\n",csc112,csc112grd);
printf(" CSC113       %d      %c\n",csc113,csc113grd);
printf(" CSC115       %d      %c\n",csc115,csc115grd);
printf(" CSC126       %d      %c\n",csc126,csc126grd);


}
