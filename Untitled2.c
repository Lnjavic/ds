#include<stdio.h>
void main()
{

    /*
    switch statements are used instead of the if else statements where the logical
    operator used is ==

    Example
    Program that does different arithmetic operations given the operator

    */

    char operator1;
    int number1,number2,sum,sub,div,mult,mod;
    printf("Enter the first number \n");
    scanf("%d",&number1);
    printf("Enter the second number \n");
    scanf("%d",&number2);
    getchar();
    printf("Enter the operator to carry (+,-,*,/)\n");
    scanf("%c",&operator1);

    switch(operator1)
    {
    case'+':
        sum=number1+number2;
        printf("The addition of the two numbers is %d\n",sum);
        break;
    case '-':
        sub=number1-number2;

        printf("The subtraction of the two numbers is %d\n",sub);
        break;
    case '*':
        mult=number1*number2;
        printf("The multiplication of the two numbers is %d\n",mult);
        break;
    case '/':
        div=number1/number2;
        printf("The division of the two numbers is %d\n",div);
        break;
    default:
        printf("Invalid operator\n");

    }
}
