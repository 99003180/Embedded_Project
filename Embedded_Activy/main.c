#include<stdio.h>
#include"sum_of_digits.h"


int main()
{
int num;
printf("Enter a number: ");
scanf("%d",&num);
int sum = summation(num);
printf("The sum of the digits of the given number is %d",sum);
}
