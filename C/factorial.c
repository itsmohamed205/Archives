#include <stdio.h>
int factorial(int number)
{
    if (number <= 1)
        return 1;
    else
        return number * factorial(number - 1);
}

int main(void)
{
    int number;
    printf("Input the number: ");
    scanf("%d", &number);
    printf("Result: %d", factorial(number));
}