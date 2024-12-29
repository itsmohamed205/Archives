#include <stdio.h>

int Fib(int number)
{
    if (!number || number == 1)
        return number;
    else
        return Fib(number - 1) + Fib(number - 2);
}

int main(void)
{
    int number;
    printf("Input the number: ");
    scanf("%d", &number);
    printf("Resutls: %d", Fib(number));
    return 0;
}