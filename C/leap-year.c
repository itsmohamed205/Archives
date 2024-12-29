#include <stdio.h>

int checkLeapYear(int year)
{

    if (!(year % 400) || !(year % 4) && (year % 100))
        return 1;
    else
        return 0;
}

int main()
{
    int i, n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    printf("Leap years from 1 to %d:\n", n);

    for (i = 1; i <= n; i++)
    {

        if (checkLeapYear(i))
            printf("%d\t", i);
    }
    return 0;
}