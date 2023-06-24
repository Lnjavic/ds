void main(){
int month;
printf("Enter number of your birth month ie [1-12]\n");
scanf("%d",&month);
switch(month){
case 1:
printf("You were born in January");
break;

case 2:
printf("You were born in February");
break;

case 3:
printf("You were born in March");
break;

case 4:
printf("You were born in April");
break;

case 5:
printf("You were born in May");
break;

case 6:
printf("You were born in June");
break;

case 7:
printf("You were born in July");
break;

case 8:
printf("You were born in August");
break;

case 9:
printf("You were born in September");
break;

case 10:
printf("You were born in October");
break;

case 11:
printf("You were born in November");
break;
case 12:
printf("You were born in December");
break;


default:
    printf("invalid :; A year has 12 months");
    break;


}
}
